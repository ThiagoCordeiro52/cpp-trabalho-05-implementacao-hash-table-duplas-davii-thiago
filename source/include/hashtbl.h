// @author: Selan
//
#ifndef _HASHTBL_H_
#define _HASHTBL_H_

#include <iostream>     // cout, endl, ostream
#include <forward_list> // forward_list
#include <algorithm>    // copy, find_if, for_each
#include <cmath>        // sqrt
#include <iterator>     // std::begin(), std::end()
#include <initializer_list>
#include <memory>
#include <utility> // std::pair

namespace ac // Associative container
{
	template<class KeyType, class DataType>
	struct HashEntry {


        // Regular constructor.
        HashEntry( KeyType kt_, DataType dt_ ) : m_key{kt_} , m_data{dt_}
        {/*Empty*/}
                KeyType m_key;   //! Data key
        DataType m_data; //! The data

        friend std::ostream & operator<<( std::ostream & os_, const HashEntry & he_ ) {
            os_ << he_.m_key << " => " << he_.m_data;
            // os_ << he_.m_data;
            return os_;
        }
    };

	template< class KeyType,
		      class DataType,
		      class KeyHash = std::hash< KeyType >,
		      class KeyEqual = std::equal_to< KeyType > >
	class HashTbl {
        public:
            // Aliases
            using entry_type = HashEntry<KeyType,DataType>;
            using list_type = std::forward_list< entry_type >;
            using size_type = std::size_t;

            /**
             * @brief Constructs a HashTbl with size table_sz_
             *
             * @param table_sz_ the size of the HashTbl
             */
            explicit HashTbl( size_type table_sz_ = DEFAULT_SIZE );
            /**
             * @brief Constructs a HashTbl as a copy of source
             *
             * @param source the HashTbl to get the values from
             */
            HashTbl( const HashTbl& source );
            /**
             * @brief Constructs a HashTbl with the values of ilist
             *
             * @param ilist the initializer list to get the values from
             */
            HashTbl( const std::initializer_list< entry_type > & ilist );
            /**
             * @brief Assign the values of clone to this HashTbl
             *
             * @param clone the HashTbl to get the values from
             *
             * @return a reference to this HashTbl
             */
            HashTbl& operator=( const HashTbl& clone );
            /**
             * @brief Assign the values of ilist to this HashTbl
             *
             * @param ilist the initializer_list to get the valeus from
             *
             * @return a reference to this HashTbl
             */
            HashTbl& operator=( const std::initializer_list< entry_type > & ilist );

            /**
             * @brief Destructs this HashTbl
             */
            virtual ~HashTbl();

            /**
             * @brief Inserts new_data into this HashTbl at key key
             *
             * @param key the key to insert the data at
             * @param new_data the new_data to be inserted
             *
             * @return whether this is the fisrt time a value is inserted at key
             */
            bool insert( const KeyType & key, const DataType & new_data );
            /**
             * @brief Checks if there is a value at key and put its value at data_item
             *
             * @param key the key to retrieve data from
             * @param data_item a reference to where to store the data found in key
             *
             * @return whether the value was found or not
             */
            bool retrieve( const KeyType & key, DataType & data_item ) const;
            /**
             * @brief Erase the value at key
             *
             * @param key the key to erase the data from
             *
             * @return wheter any value was erased
             */
            bool erase( const KeyType & key );
            /**
             * @brief Erases all the data from HashTbl
             */
            void clear();
            /**
             * @return wheter this HashTbl is empty
             */
            bool empty() const;
            /**
             * @return the quantity of elements in this HashTbl
             */
            inline size_type size() const { return m_count; };
            /**
             * @brief Returns the value at key, throws an exception if no value is found
             *
             * @param key the key to get the data from
             *
             * @return the value at key
             */
            DataType& at( const KeyType& key );
            /**
             * @brief Returns the value at key, inserts a new value if none is found
             *
             * @param key the key to get the data from
             *
             * @return the value at key
             */
            DataType& operator[]( const KeyType& key );
            /**
             * @return the quantity of elements is the list associated with key
             */
            size_type count( const KeyType& key ) const;
            /**
             * @return the max load factor
             */
            float max_load_factor() const;
            /**
             * @brief Sets the max load factor to mlf
             *
             * @param mlf the new value of max load factor
             */
            void max_load_factor(float mlf);

            /**
             * @brief Transforms ht to string and appends to os
             */
            friend std::ostream & operator<<( std::ostream & os, const HashTbl & ht ) {
                os << "{ ";
                for (auto i{0u}; i < ht.m_size; i++) {
                    for (auto it{ht.m_table[i].begin()}; it != ht.m_table[i].end(); it++) {
                        os << *it << ", ";
                    }
                }
                os << '}';
                return os;
            }

        private:
            /**
             * @return the least prime greater than n
             */
            static size_type find_next_prime( size_type n );
            /**
             * @return wheter n is prime
             */
            static bool is_prime( size_type n );
            /**
             * @brief Increases the size of the HashTbl and recalculates the positions of all values
             */
            void rehash( void );

        private:
            size_type m_size; //!< Tamanho da tabela.
            size_type m_count;//!< Numero de elementos na tabel.
            std::unique_ptr<list_type[]> m_table; //!< Tabela de listas para entradas de tabela.
            float m_max_load_factor;
            static const short DEFAULT_SIZE = 11;
    };

} // MyHashTable
#include "hashtbl.inl"
#endif
