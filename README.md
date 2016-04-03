# Hash-Join-Simulation
---
###Simulation of the HASH JOIN techniques used by DBMS to perform Equality Join
---
* The two relations on which the equality join is being done should have one cloumn and integral values.
* The name of the two files are rel1.txt rel2.txt 
* Input Format : relation1_record_size relation2_record_size  page_size  number_of_buffer_pages number_of_hashing_rounds
  

###Example command
`> g++ hash_join.cpp`  
`> ./a.out`  
`> 180 130 400 5 3`

Here,
* Relation1 record size is : 180
* Relation2 record size is : 130
* Page size is : 400
* Number of available buffer pages (1 page is reserved for output buffer) is : 5 
* Number of hashing rounds is : 3 

