#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <string.h>

#include <iostream>

//产生公私钥的函数，公钥加密，私钥解密
//g++ -o rsa rsa.cpp -lcrypto
//密钥可能含有\0, 不能用cout输出
//snprintf((char *)&pubkeyx[i*2], 2, "%02x", pub_key[i]), %02x可以，%02X
//待加密的原文不能超过8个字节，超过的话需要分8字节进行加解密

int gen_key(char* pub_key, int* pub_key_len, char* priv_key, int* priv_key_len, int key_bit_count)
{
    RSA* rsa = RSA_new();
    rsa = RSA_generate_key(key_bit_count, RSA_F4, NULL, NULL);

    if (rsa == NULL)
    {
        return 1;
    }

    unsigned char* pub_key_tmp = NULL;
    *pub_key_len = i2d_RSA_PUBKEY(rsa, &pub_key_tmp);
    memcpy(pub_key, (char*)pub_key_tmp, *pub_key_len);
   
    unsigned char* priv_key_tmp = NULL;
    *priv_key_len = i2d_RSAPrivateKey(rsa, &priv_key_tmp);
    memcpy(priv_key, (char*)priv_key_tmp, *priv_key_len);

    RSA_free(rsa);

    return 0;
}

int encrypt_pub(const char* plaintext, char* ciphertext, const unsigned char* pub_key, int pub_key_len)
{
    RSA* rsa = RSA_new();
  
    d2i_RSA_PUBKEY(&rsa, (unsigned char**)&pub_key, pub_key_len);
    int rsa_len = RSA_size(rsa);
    std::cout<<"encrypt len is "<<rsa_len<<std::endl;
    int ret = RSA_public_encrypt(rsa_len, (unsigned char*)plaintext, (unsigned char*)ciphertext, rsa, RSA_NO_PADDING);

    RSA_free(rsa);
    return ret;
}

int decrypt_priv(const char* ciphertext, char* plaintext, const char* priv_key, int priv_key_len)
{
    int ret = 0;
    RSA* rsa = RSA_new();
    const char* priv_key_tmp = priv_key;

    rsa = d2i_RSAPrivateKey(NULL, (const unsigned char**)&priv_key_tmp, priv_key_len);

    int rsa_len = RSA_size(rsa);
    std::cout<<"decrypt len is "<<rsa_len<<std::endl;
    ret = RSA_private_decrypt(rsa_len, (unsigned char*)ciphertext, (unsigned char*)plaintext, rsa, RSA_NO_PADDING);

    if (rsa != NULL)
    {
        RSA_free(rsa);
    }

    return ret;
}

int main()
{
    char* pub_key = new char[1024];
    char* priv_key = new char[1024];
    int pub_key_len = 0;
    int priv_key_len = 0;

    int ret = gen_key(pub_key, &pub_key_len, priv_key, &priv_key_len, 512);

    if (ret != 0)
    {
        std::cout<<"gen key error"<<std::endl;
        return 1;
    }

    std::cout<<"pub len is "<<pub_key_len<<std::endl;
    std::cout<<"priv len is "<<priv_key_len<<std::endl;

    //输出的值应该为实际密钥长度*2

    char *pubkeyx = new char[1024];
    memset(pubkeyx, 0, 1024);

    char *prikeyx = new char[1024];
    memset(prikeyx, 0, 1024);

    for (int i=0; i<pub_key_len; i++)
    {
        snprintf((char *)&pubkeyx[i*2], 2, "%02x", pub_key[i]);
        std::cout<<pubkeyx[i*2]<<pubkeyx[i*2+1];
    }

    pubkeyx[pub_key_len*2] = '\0';
    std::cout<<std::endl;

    for (int i=0; i<priv_key_len; i++)
    {
        snprintf((char *)&prikeyx[i*2], 2, "%02x", priv_key[i]);
        std::cout<<prikeyx[i*2]<<prikeyx[i*2+1];
    }
    
    prikeyx[priv_key_len*2] = '\0';
    std::cout<<std::endl;

    //公钥加密
    char msg[10] = "karry02";
    std::cout<<"src val is "<<msg<<std::endl;
    char encryptmsg[1024] = {0};
    encrypt_pub(msg, encryptmsg, (const unsigned char*)pub_key, pub_key_len);

    //私钥解密
    char decryptmsg[1024] = {0};
    decrypt_priv(encryptmsg, decryptmsg, priv_key, priv_key_len);
    std::cout<<"decrypt val is "<<decryptmsg<<std::endl;

    delete [] pubkeyx;
    delete [] prikeyx;

    delete [] pub_key;
    delete [] priv_key;
}
