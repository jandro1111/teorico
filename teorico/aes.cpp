#include"lib.h"
aes::aes(int clave) {
    memset(key, clave, CryptoPP::AES::DEFAULT_KEYLENGTH);//la llave  opcional para hacer random el cifrado (rand() % 100)
    memset(iv, 1, CryptoPP::AES::BLOCKSIZE);//vector de inicializacion opcional para hacer random el cifrado (rand() % 100)
    //Key and IV setup
    //AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-   
    //bit). This key is secretly exchanged between two parties before communication   
    //begins. DEFAULT_KEYLENGTH= 16 bytes
}
aes::aes(void) {
    memset(key, 1, CryptoPP::AES::DEFAULT_KEYLENGTH);//la llave  opcional para hacer random el cifrado (rand() % 100)
    memset(iv, 1, CryptoPP::AES::BLOCKSIZE);//vector de inicializacion opcional para hacer random el cifrado (rand() % 100)
    //Key and IV setup
    //AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-   
    //bit). This key is secretly exchanged between two parties before communication   
    //begins. DEFAULT_KEYLENGTH= 16 bytes
}
//cifrado simetrico
//basado en  https://stackoverflow.com/questions/12306956/example-of-aes-using-crypto   
std::string aes::aesencrypt(std::string plaintext) {
    // String and Sink setup
    //
    std::string ciphertext;

    //
    // Dump Plain Text
    //
    std::cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
    std::cout << plaintext;
    std::cout << std::endl << std::endl;

    //
    // Create Cipher Text
    //
    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);//primero forma de encriptar, simetrica -> aes
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, iv);//forma de encriptar los bloques -> cbc

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink(ciphertext));//padding de bloques
    stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length());//inserto el contenido
    stfEncryptor.MessageEnd();

    //
    // Dump Cipher Text
    //
    std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;

    for (int i = 0; i < ciphertext.size(); i++) {

        std::cout << "" << (static_cast<CryptoPP::byte>(ciphertext[i])) << "";//"0x"<<std::hex<< 0xFF & static-cast   para hexa 
    }

    std::cout << std::endl << std::endl;
    return ciphertext;
}
std::string aes::aesdecrypt(std::string ciphertext) {
    // String and Sink setup
    std::string decryptedtext;

    //
    // Decrypt
    //
    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, iv);

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
    stfDecryptor.Put(reinterpret_cast<const unsigned char*>(ciphertext.c_str()), ciphertext.size());
    stfDecryptor.MessageEnd();

    //
    // Dump Decrypted Text
    //
    std::cout << "Decrypted Text: " << std::endl;
    std::cout << decryptedtext;
    std::cout << std::endl << std::endl;
    return decryptedtext;
}
