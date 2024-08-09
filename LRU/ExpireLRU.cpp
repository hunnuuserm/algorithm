template<class K, class V>
struct ELRUNode
{
	ELRUNode(const K& key, const V& value, const time_t& expire_time)
		:_key(key)
		,_value(value)
		, _expire_time(expire_time)
	{}
	K _key;
	V _value;
	time_t _expire_time;
};

template<class K, class V>
class ExpireLRUCache
{
public:
	ExpireLRUCache(const int& capacity, const time_t& ttl)
		:_capacity(capacity),
		_ttl(ttl)
	{}
	void Put(const K& key, const V& value)
	{
		auto now = time(nullptr);
		auto it = _hash.find(key);
		if (it != _hash.end())
		{
			//当前有存的此key
			_list.erase(it->second);
			_list.push_front({ key, value, now + _ttl });
			_hash[key] = _list.begin();
			return;
		}

		if (_hash.size() == _capacity)
		{
			//先检查有没有过期的
			auto it = _hash.begin();
			while (it != _hash.end())
			{
				if (now > it->second->_expire_time)
				{
					//已过期，删除此元素
					_list.erase(it->second);
					_hash.erase(it);
					break;
				}
				++it;
			}

			if (_hash.size() == _capacity)
			{
				auto it = --_list.end();
				_hash.erase(it->_key);
				_list.pop_back();
			}
		}
		_list.push_front({ key, value, now + _ttl });
		_hash[key] = _list.begin();
	}
	std::optional<V> Get(const K& key)
	{
		auto it = _hash.find(key);
		if (it == _hash.end())
			return std::nullopt;
		
		//有当前查找的元素，先判断是否过期
		auto now = time(nullptr);
		if (now > it->second->_expire_time)
			return std::nullopt;

		V value = it->second->_value;
		time_t time = it->second->_expire_time;
		_list.erase(it->second);
		_list.push_front({ key, value, time });
		_hash[key] = _list.begin();
		return value;
	}
private:
	int _capacity;
	time_t _ttl;//time to live
	std::unordered_map<K, typename list<ELRUNode<K, V>>::iterator> _hash;
	std::list<ELRUNode<K, V>> _list;
};


int main()
{
	ExpireLRUCache<int, std::string> cache(3, 5);  // 容量为3, 过期时间为5秒

	cache.Put(1, "one");
	cache.Put(2, "two");
	cache.Put(3, "three");

	if (auto res = cache.Get(1))
		std::cout << "Key 1: " << *res << std::endl;
	else
		std::cout << "Key 1 expired or not found" << std::endl;

	if (auto res = cache.Get(2))
		std::cout << "Key 2: " << *res << std::endl;
	else
		std::cout << "Key 2 expired or not found" << std::endl;
	
	if (auto res = cache.Get(3))
		std::cout << "Key 3: " << *res << std::endl;
	else
		std::cout << "Key 3 expired or not found" << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(6));  // 等待6秒，确保第一个元素过期

	cache.Put(4, "four");  // 插入新元素，检查过期机制

	if (auto result = cache.Get(1)) {
		std::cout << "Key 1: " << *result << std::endl;
	}
	else {
		std::cout << "Key 1 expired or not found" << std::endl;
	}

	if (auto result = cache.Get(2)) {
		std::cout << "Key 2: " << *result << std::endl;
	}
	else {
		std::cout << "Key 2 expired or not found" << std::endl;
	}

	return 0;
}