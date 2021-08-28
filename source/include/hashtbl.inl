#include "hashtbl.h"

namespace ac {
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>::HashTbl( size_type sz  )
	{
        auto result = is_prime(sz);
        if(result) {
            m_size = sz;
        } else {
            m_size = find_next_prime(sz);
        }
        m_count = 0;
        m_table = std::unique_ptr<std::forward_list<entry_type>[]>(new std::forward_list<entry_type>[m_size]);
	}

    /// Copy constructor
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>::HashTbl( const HashTbl& source )
	{
        // TODO
	}

    /// Initializer constructor
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>::HashTbl( const std::initializer_list<entry_type>& ilist )
    {
        m_size = DEFAULT_SIZE;
        m_count = 0;
        m_table = std::unique_ptr<std::forward_list<entry_type>[]>(new std::forward_list<entry_type>[m_size]);
        for (auto& e: ilist)
            insert(e.m_key, e.m_data);
    }

    // TODO: relook this method
    /// Assignment operator.
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>&
    HashTbl<KeyType,DataType,KeyHash,KeyEqual>::operator=( const HashTbl& clone )
    {
        if (m_size != clone.m_size) {
            m_size = clone.m_size;
            auto new_table {std::unique_ptr<list_type[]>(new list_type[m_size])};
            m_table = std::move(new_table);
        } else {
            for (auto i{0u}; i < m_size; i++) {
                m_table[i] = clone.m_table[i];
            }
        }

        return *this;
    }

    /// Assignment initializer list.
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>&
    HashTbl<KeyType,DataType,KeyHash,KeyEqual>::operator=( const std::initializer_list< entry_type >& ilist )
    {
        // TODO
        return *this;
    }


	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>::~HashTbl( )
	{
        /* empty */
	}

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	bool HashTbl<KeyType,DataType,KeyHash,KeyEqual>::insert( const KeyType & key, const DataType & new_data )
    {
       KeyHash hashFunc; // Instantiate the " functor " for primary hash.
       KeyEqual equalFunc; // Instantiate the " functor " for the equal to test.
       entry_type new_entry { key, new_data }; // Create a new entry based on arguments.
       // Apply double hashing method , one functor and the other with modulo function.
       auto end { hashFunc( key ) % m_size };
       auto auxiliaryFirst = m_table[end].begin();
        while (auxiliaryFirst != m_table[end].end()) {
            // Comparing keys inside the collision list.
            auto it = *auxiliaryFirst;
            if ( true == equalFunc( it.m_key , new_entry.m_key ) )
            {
                it = new_entry;
                return false;
            }
            auxiliaryFirst++;
        }
        m_table[end].push_front(new_entry);
        m_count++;
        return true;

    }
	
    //! Clears the data table.
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear()
    {
        for (auto i{0u}; i < m_size; i++) {
            m_table[i].clear();
        }
        m_count = 0;
    }

    //! Tests whether the table is empty.
    /*!
     * \return true is table is empty, false otherwise.
     */
    template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::empty() const
    {
        if(m_count == 0) {
            return true;
        }
        return false; // This is just a stub. Reaplace it accordinly.
    }

    //----------------------------------------------------------------------------------------
    //! Retrieves data from the table.
    /*! Retrieves a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param key_ Data key to search for in the table.
     *  \param data_item_ Data record to be filled in when data item is found.
     *  \return true if the data item is found; false, otherwise.
     */
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::retrieve( const KeyType & key_, DataType & data_item_ ) const
    {
        // TODO
        return false; // This is just a stub. Reaplace it accordinly.
    }

    /// Rehash
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::rehash( void )
    {
        auto hash_function {KeyHash{}};

        auto new_size {find_next_prime(m_size * 2)};
        auto new_table {std::unique_ptr<list_type[]>(new list_type[new_size])};

        for (auto i {0u}; i < m_size; i++) {
            for (auto it {m_table[i].begin()}; it != m_table[i].begin(); it++) {
                auto pos {hash_function(it->key) % new_size};
                new_table[pos].emplace_front(it->m_key, it->m_data);
            }
        }

        m_table = std::move(new_table);
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::erase( const KeyType & key )
    {
        auto pos {KeyHash{}(key) % m_size};
        auto equal_func {KeyEqual{}};
        for (auto it {m_table[pos].begin()}; it != m_table[pos].end(); it++) {
            if (equal_func(it->m_key, key)) {
                m_table[pos].erase_after(it);
                return true;
            }
        }
        return false;
    }

    /// Check if the number n is prime 
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl<KeyType,DataType,KeyHash,KeyEqual>::is_prime( size_type  n ) {
        int counter{0};
        for (int i = 1; i <= (int) sqrt(n); i++) {
            if(n % i == 0) {
                counter++;
            }
        }
        if(counter > 1) {
            return true;
        }
        return false;
    }

    /// Find the next prime >= n_
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    std::size_t HashTbl<KeyType,DataType,KeyHash,KeyEqual>::find_next_prime( size_type  n )
    {
        for(int i = n; i < n + n; i++) {
            auto result = is_prime(i);
            if (result) {
                return i;
            }
        }
        return 0; // Stub
    }


	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    typename HashTbl< KeyType, DataType, KeyHash, KeyEqual >::size_type
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::count( const KeyType & key ) const
    {
        auto pos {KeyHash{}(key) % m_size};
        auto count {0u};
        auto equal_func {KeyEqual{}};
        for (auto it {m_table[pos].begin()}; it != m_table[pos].end(); it++) {
            if (equal_func(it->m_key, key))
                count++;
        }
        return count;
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    DataType& HashTbl<KeyType, DataType, KeyHash, KeyEqual>::at( const KeyType & key_ )
    {
        // TODO
        return m_table[0].begin()->m_data; // Stub
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    DataType& HashTbl<KeyType, DataType, KeyHash, KeyEqual>::operator[]( const KeyType & key )
    {
        auto pos {KeyHash{}(key) % m_size};
        auto equal_func {KeyEqual{}};
        for (auto it {m_table[pos].begin()}; it != m_table[pos].end(); it++) {
            if (equal_func(it->m_key, key))
                return it->m_data;
        }
        m_table[pos].emplace_front(key, DataType{});
        return m_table[pos].front().m_data; // Stub
    }
} // Namespace ac.
