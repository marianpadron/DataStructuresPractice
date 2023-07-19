#include "hashmap.h"


/**
 * just a sample run for testing. 
*/

/**
* Test count function.
*/
int test1() {
  hashmap map = map_create(2);
  int count = count_map(map);

  if (count != 0) {
    return 0;
  }

  // add to map
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);

  count = count_map(map);
  map_free(map);

  if (count != 2) {
    return 0;
  }

  return 1;
}

/**
* Tests a small hashmap is created;
*/
int test2() {
  hashmap map = map_create(5);

  if (map == NULL) {
    map_free(map);
    return 0;
  }
  map_free(map);
  return 1;
}

/**
* Tests a large hashmap is created;
*/
int test3() {
  hashmap map = map_create(300);
  if (map == NULL) {
    map_free(map);
    return 0;
  }
  map_free(map);
  return 1;
}

/**
* Test map_get.
*/
float test4() {
  int count = 0;
  hashmap map = map_create(3);
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test3", 3);

  if (map_get(map, "test1") == 1) {
    count++;
  }
  if (map_get(map, "test2") == 2) {
    count++;
  }
  if (map_get(map, "test3") == 3) {
    count++;
  }

  map_free(map);
  if (count != 3) {
    return 0;
  }
  return 1;
}

/**
* Test map_put.
*/
int test5() {
  hashmap map = map_create(3);
  if (count_map(map) != 0) {
    return 0;
  }
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test3", 3);

  if (count_map(map) == 3) {
    map_free(map);
    return 1;
  }
  map_free(map);
  return 0;
}

/**
* Test get invalid item.
*/
int test6() {
  hashmap map = map_create(3);
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test3", 3);
  if (map_get(map, "test4") == -1.0) {
    map_free(map);
    return 1;
  }
  map_free(map);
  return 0;
}

/**
* Test putting items that have collision.
*/
int test7() {
  hashmap map = map_create(6);
  map_put(map, "test31", 1); // hash 1
  map_put(map, "test2", 2); // hash 5
  map_put(map, "test11", 3); // hash 1
  map_put(map, "test4", 4); // hash 1
  map_put(map, "test2", 5); // hash 5
  map_put(map, "test5", 6); // hash 2

  if (count_map(map) == 6) {
    if(map_get(map, "test31") == 1 && map_get(map, "test4") == 4 && map_get(map, "test11") == 3) {
      map_free(map);
      return 1;
    }
  }
  return 0;
}

/**
* Test delete item.
*/
int test8() {
  hashmap map = map_create(3);
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test3", 3);
  int results = 0;
  if (count_map(map) == 3) {
    results++;
  }
  if (map_del(map, "test2") == 2 && count_map(map) == 2) {
    results++;
  }
  map_free(map);
  if (results == 2) {
    return 1;
  }
  return 0;
}

/**
* Test overwritting an item.
*/
int test9() {
  hashmap map = map_create(3);
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test21", 3);

  int results = 0;
  if (map_get(map, "test1") == 1 && map_get(map, "test2") == 2 && map_get(map, "test21") == 3) {
    results++;
  }

  map_put(map, "test1", 9);
  map_put(map, "test2", 12);
  map_put(map, "test21", 21);
  if (map_get(map, "test1") == 9 && map_get(map, "test2") == 12 && map_get(map, "test21") == 21 ) {
    results++;
  }  

  map_free(map);
  if(results == 2) {
    return 1;
  }
  return 0;
}

/**
* Test deleting invalid item.
*/
int test10() {
  hashmap map = map_create(3);
  map_put(map, "test1", 1);
  map_put(map, "test2", 2);
  map_put(map, "test3", 3);
  if(map_del(map, "test4") == -1.0) {
    map_free(map);
    return 1;
  }
  //map_free(map);
  return 0;
}

int main() {

    int results = 0;
    results += test1(); 
    results += test2();
    results += test3();
    results += test4();
    results += test5();
    results += test6();
    results += test7();
    results += test8();
    results += test9();
    results += test10();


    if (results == 10) {
      printf("All tests have passed.\n");
    } else {
      printf("At least one test has failed.\n");
    }
}
