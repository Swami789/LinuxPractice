#include <stdlib.h>

/*Step 5 : */

/*Return 0 if ds1 and ds2 are clones,
 * else return -1*/
int
diff (void *root1,    /*pointer to Data structure 1*/
      void *root2,    /*pointer to data structure 2*/
      void *(*iterator(void *)), /*Iterator function callback*/
      int comparator(void *, void *),
      void *(*get_app_data(void *))){  /*Comparison function callback*/

      /*Write your code here*/
      void *nextNode1 =  NULL;
      void *nextNode2 = NULL;

      if (root1 && !root2) {
            return -1;
      }
      if (!root1 && root2) {
            return -1;
      }
      if (comparator(get_app_data(root1), get_app_data(root2)))
          return -1;

      nextNode1 = iterator(root1);
      nextNode2 = iterator(root2);

      while(1) {
            if (comparator(get_app_data(nextNode1), get_app_data(nextNode2)))
                  return -1;
            nextNode1 = iterator(nextNode1);
            nextNode2 = iterator(nextNode2);

            if(!nextNode1 && !nextNode2) 
                  return 0;
      }

      return 0;
}
