#ifndef SHA256_H
#define SHA256_H
#include <string>
 
class SHA256
{
protected:
    typedef unsigned char u8;
    typedef unsigned int u32;
    typedef unsigned long long u64;
 
    const static u32 sha256_k[];
    static const unsigned int BLOCK_SIZE = (512/8);
public:
    void init();
    void update(const unsigned char *msg, unsigned int len);
    void f(unsigned char *digest);
    static const unsigned int DIGEST_SIZE = (256/8);
 
protected:
    void tf(const unsigned char *msg, unsigned int new_block);
    unsigned int mtl;
    unsigned int ml;
    unsigned char mblock[2*BLOCK_SIZE];
    u32 mh[8];
};
 
std::string sha256(std::string inp);
 
#define SHA2_SHFR(x, n)  (x >> n)
#define SHA2_ROTR(x, n)  ((x >> n) | (x << ((sizeof(x) << 3) - n)))
#define SHA2_ROTL(x, n)  ((x << n) | (x >> ((sizeof(x) << 3) - n)))
#define SHA2_CH(x, y, z) ((x & y) ^ (~x & z))
#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))
#define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
#define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
#define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))
#define SHA2_UNPACK32(x, str)                 \
{                                             \
    *((str) + 3) = (u8) ((x)      );       \
    *((str) + 2) = (u8) ((x) >>  8);       \
    *((str) + 1) = (u8) ((x) >> 16);       \
    *((str) + 0) = (u8) ((x) >> 24);       \
}
#define SHA2_PACK32(str, x)                   \
{                                             \
    *(x) =   ((u32) *((str) + 3)      )    \
           | ((u32) *((str) + 2) <<  8)    \
           | ((u32) *((str) + 1) << 16)    \
           | ((u32) *((str) + 0) << 24);   \
}
#endif
