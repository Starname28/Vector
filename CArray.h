#pragma once

template<typename TData>
class CArray
{
public:
	CArray();

	CArray(
		const CArray& _array
	  );

	~CArray();

	void push_back(
		const TData& _value
	  );

	void insert(
		unsigned int _index,
		const TData& _value
	  );

	void erase(
		unsigned int _index
	  );
	
	void clear();

	unsigned int size() const;

	TData& operator[](
		unsigned int _index
	  );

	TData& operator[](
		unsigned int _index
		) const;

	unsigned int capacity() const;

	TData* begin();
	TData* begin() const;

	TData* end();
	TData* end() const;

protected:
	TData* m_data;
	int    m_size, m_capacity;
};

template<typename TData>
inline CArray<TData>::CArray()
	: m_data(nullptr),
	m_size(0),
	m_capacity(0)
{}

template<typename TData>
inline CArray<TData>::CArray(
	const CArray & _array
  )
{
	m_size = _array.size();
	m_capacity = _array.capacity();

	m_data = new TData[capacity()];

	for (int i = 0; i < size(); ++i)
		m_data[i] = _array[i];
}

template<typename TData>
inline CArray<TData>::~CArray()
{
	clear();
}

template<typename TData>
inline void CArray<TData>::push_back(
	const TData& _value
  )
{
	if (!m_data)
	{
		m_data = new TData[1];

		m_size = 1;
		m_capacity = 1;

		m_data[0] = _value;

		return;
	}

	if (size() == capacity())
	{
		TData* tmp = new TData[size() + 1];

		for (int i = 0; i < size(); i++)
			tmp[i] = m_data[i];

		tmp[size()] = _value;

		delete[] m_data;
		m_data = nullptr;

		m_capacity *= 2;
		++m_size;

		m_data = new TData[capacity()];

		for (int i = 0; i < size(); ++i)
			m_data[i] = tmp[i];

		delete[] tmp;
	}
	else
	{
		m_data[size()] = _value;
		++m_size;
	}
}

template<typename TData>
inline void CArray<TData>::insert(
	unsigned int _index, 
	const TData& _value
  )
{
	if (_index > size() - 1 || !m_data)
	{
		push_back(_value);
		return;
	}

	if (size() == capacity())
	{
		TData* tmp = new TData[size() + 1];

		for (int i = 0, j = 0; i < size()+1; ++i, ++j)
		{
			if (i == _index)
			{
				tmp[i] = _value;
				--j;
				continue;
			}
			else
			{
				tmp[i] = m_data[j];
			}
		}

		delete[] m_data;
		m_data = nullptr;

		m_capacity *= 2;
		++m_size;

		m_data = new TData[capacity()];

		for (int i = 0; i < size(); ++i)
			m_data[i] = tmp[i];

		delete[] tmp;
	}
	else
	{
		++m_size;

		for (int i = size() - 1; i > _index; --i)
		{
			m_data[i] = m_data[i - 1];
		}

		m_data[_index] = _value;
	}
}

template<typename TData>
inline void CArray<TData>::erase(
	unsigned int _index
  )
{
	if (_index > size() - 1)
		return;

	for (int i = _index + 1; i < size(); ++i)
	{
		m_data[i - 1] = m_data[i];
	}

	--m_size;
}

template<typename TData>
inline void CArray<TData>::clear()
{
	delete[] m_data;
	m_data = nullptr;

	m_capacity = 0;
	m_size = 0;
}

template<typename TData>
inline unsigned int CArray<TData>::size() const
{
	return m_size;
}

template<typename TData>
inline TData& CArray<TData>::operator[](
	unsigned int _index
  )
{
	return m_data[_index];
}

template<typename TData>
inline TData& CArray<TData>::operator[](unsigned int _index) const
{
	return m_data[_index];
}

template<typename TData>
inline unsigned int CArray<TData>::capacity() const
{
	return m_capacity;
}

template<typename TData>
inline TData* CArray<TData>::begin()
{
	return m_data;
}

template<typename TData>
inline TData* CArray<TData>::begin() const
{
	return m_data;
}

template<typename TData>
inline TData* CArray<TData>::end()
{
	return m_data + size();
}

template<typename TData>
inline TData* CArray<TData>::end() const
{
	return m_data + size();
}
