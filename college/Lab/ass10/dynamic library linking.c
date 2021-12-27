http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html


@followed for static linking
https://www.geeksforgeeks.org/static-vs-dynamic-libraries/
3. Link the compiled driver program to the static library. Note that -L. 
 is used to tell that the static library is in current folder (See this for details of -L and -l options). 
  
  
gcc -o driver driver.o -L. -l:lib_mylib.a


https://gist.github.com/tailriver/30bf0c943325330b7b6a


