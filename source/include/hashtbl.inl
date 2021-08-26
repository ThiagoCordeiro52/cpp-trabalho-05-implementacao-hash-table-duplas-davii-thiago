#include "hashtbl.h"

namespace ac {
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>::HashTbl( size_type sz )
	{
        // TODO
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
        // TODO
    }

    /// Assignment operator.
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	HashTbl<KeyType,DataType,KeyHash,KeyEqual>&
    HashTbl<KeyType,DataType,KeyHash,KeyEqual>::operator=( const HashTbl& clone )
    {
        // TODO
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
        // TODO
	}

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
	bool HashTbl<KeyType,DataType,KeyHash,KeyEqual>::insert( const KeyType & key_, const DataType & new_data_ )
    {
        // TODO
        return false; // This is just a stub. Reaplace it accordinly.
    }
	
    //! Clears the data table.
    template <typename KeyType, typename DataType, typename KeyHash, typename KeyEqual>
    void HashTbl<KeyType, DataType, KeyHash, KeyEqual>::clear()
    {
        // TODO
    }

    //! Tests whether the table is empty.
    /*!
     * \return true is table is empty, false otherwise.
     */
    template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl<KeyType, DataType, KeyHash, KeyEqual>::empty() const
    {
        // TODO
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
        // TODO
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::erase( const KeyType & key_ )
    {
        // TODO
        return false; // This is just a stub. Reaplace it accordinly.
    }


    /// Find the next prime >= n_
	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    std::size_t HashTbl<KeyType,DataType,KeyHash,KeyEqual>::find_next_prime( size_type  n_ )
    {
        // TODO
        return 0; // Stub
    }


	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    typename HashTbl< KeyType, DataType, KeyHash, KeyEqual >::size_type
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::count( const KeyType & key_ ) const
    {
        // TODO
        return 0; // Stub
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    DataType& HashTbl<KeyType, DataType, KeyHash, KeyEqual>::at( const KeyType & key_ )
    {
        // TODO
        return m_table[0].begin()->m_data; // Stub
    }

	template< typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    DataType& HashTbl<KeyType, DataType, KeyHash, KeyEqual>::operator[]( const KeyType & key_ )
    {
        // TODO
        return m_table[0].begin()->m_data; // Stub
    }
} // Namespace ac.
