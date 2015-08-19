/*
 ID: spleens2
 PROG: file
 LANG: C++
*/

#define UPLOAD 1
#if UPLOAD
#define openFiles() freopen("file.in", "r", stdin); freopen("file.out", "w", stdout)
#else
#define openFiles()
#endif
