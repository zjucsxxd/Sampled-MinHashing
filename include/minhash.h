/**
 * @file minhash.h
 * @author Gibran Fuentes Pineda <gibranfp@turing.iimas.unam.mx>
 * @date 2013
 *
 * @section GPL
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @brief Declaration of structures and functions for the Min-Hash-based clustering.
 */
#ifndef MINHASH_H
#define MINHASH_H

#include <inttypes.h>
#include "types.h"
#include "listdb.h"

typedef struct RandomValue
{
     uint random_int;
     double random_double;
} RandomValue;

typedef struct Bucket{
     uint hash_value;
     List items;
} Bucket;

typedef struct HashTable {
	uint table_size; 
	uint tuple_size; 
	uint dim;
	RandomValue *permutations;
	Bucket *buckets;
	List used_buckets;
	uint *a;
	uint *b;
} HashTable;


/************************ Function prototypes ************************/
void mh_print_head(HashTable *);
void mh_print_table(HashTable *);
void mh_init(HashTable *);
HashTable mh_create(uint, uint, uint);
void mh_destroy(HashTable *);
void mh_erase_from_list(List *, HashTable *);
void mh_erase_from_index(uint, HashTable *);
void mh_generate_permutations(uint, uint, RandomValue *);
int mh_random_value_compare(const void *, const void *);
uint mh_compute_minhash(List *, RandomValue *);
void mh_univhash(List *, HashTable *, uint *, uint *);
uint mh_get_index(List *, HashTable *);
uint mh_store_list(List *, uint, HashTable *);
void mh_store_listdb(ListDB *, HashTable *, uint *);
#endif
