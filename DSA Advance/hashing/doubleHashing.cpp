// Double hashing
//  we have 3 hash functions and we use them to insert keys
//  h1(x) = x%10
// h2(x) = R- (x % R) //here r is primary number that is smaller than size of hashtable it is suggested hash function
// h'(x) =(h1(x) + i *h2(x))%10 where i = 0,1,2,3
// first we use h1 if there is any colision we se h' it alwase give a diffrent index to store diffrent keys
// but some time we have to check diffrent vlaues of i to git our index