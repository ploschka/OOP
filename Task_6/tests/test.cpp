#include "gtest/gtest.h"
#include "Base64.h"

TEST(Base64EncodeTest, Encode3xLengthString)
{
    EXPECT_EQ("TG94", Base64::encode("Lox"));
    EXPECT_EQ("TG94b3ph", Base64::encode("Loxoza"));
    EXPECT_EQ("TG94b3phdnJp", Base64::encode("Loxozavri"));
    EXPECT_EQ("TG94b3phdnJpayBk", Base64::encode("Loxozavrik d"));
    EXPECT_EQ("TG94b3phdnJpayBkYXVu", Base64::encode("Loxozavrik daun"));
}

TEST(Base64EncodeTest, Encode2xLengthString)
{
    EXPECT_EQ("UmE=", Base64::encode("Ra"));
    EXPECT_EQ("UmFuZG8=", Base64::encode("Rando"));
    EXPECT_EQ("UmFuZG9tIHM=", Base64::encode("Random s"));
    EXPECT_EQ("UmFuZG9tIHN0cmk=", Base64::encode("Random stri"));
    EXPECT_EQ("UmFuZG9tIHN0cmluZyA=", Base64::encode("Random string "));
    EXPECT_EQ("UmFuZG9tIHN0cmluZyBsb3g=", Base64::encode("Random string lox"));
}

TEST(Base64EncodeTest, Encode1xLengthString)
{
    EXPECT_EQ("Tg==", Base64::encode("N"));
    EXPECT_EQ("Tm90IA==", Base64::encode("Not "));
    EXPECT_EQ("Tm90IHNvIA==", Base64::encode("Not so "));
    EXPECT_EQ("Tm90IHNvIHJhbg==", Base64::encode("Not so ran"));
    EXPECT_EQ("Tm90IHNvIHJhbmRvbQ==", Base64::encode("Not so random"));
    EXPECT_EQ("Tm90IHNvIHJhbmRvbSBzdA==", Base64::encode("Not so random st"));
    EXPECT_EQ("Tm90IHNvIHJhbmRvbSBzdHJpbg==", Base64::encode("Not so random strin"));
    EXPECT_EQ("Tm90IHNvIHJhbmRvbSBzdHJpbmcgIQ==", Base64::encode("Not so random string !"));
}

TEST(Base64EncodeTest, EncodeEmptyString)
{
    EXPECT_EQ("", Base64::encode(""));
}

TEST(Base64DecodeTest, Decode0EqualityString)
{
    EXPECT_EQ("C++", Base64::decode("Qysr"));
    EXPECT_EQ("C++ is", Base64::decode("QysrIGlz"));
    EXPECT_EQ("C++ is th", Base64::decode("QysrIGlzIHRo"));
    EXPECT_EQ("C++ is the b", Base64::decode("QysrIGlzIHRoZSBi"));
    EXPECT_EQ("C++ is the best", Base64::decode("QysrIGlzIHRoZSBiZXN0"));
    EXPECT_EQ("C++ is the best la", Base64::decode("QysrIGlzIHRoZSBiZXN0IGxh"));
    EXPECT_EQ("C++ is the best langu", Base64::decode("QysrIGlzIHRoZSBiZXN0IGxhbmd1"));
    EXPECT_EQ("C++ is the best language", Base64::decode("QysrIGlzIHRoZSBiZXN0IGxhbmd1YWdl"));
}

TEST(Base64DecodeTest, Decode1EqualityString)
{
    EXPECT_EQ("Py", Base64::decode("UHk="));
    EXPECT_EQ("Pytho", Base64::decode("UHl0aG8="));
    EXPECT_EQ("Python i", Base64::decode("UHl0aG9uIGk="));
    EXPECT_EQ("Python is k", Base64::decode("UHl0aG9uIGlzIGs="));
    EXPECT_EQ("Python is kind", Base64::decode("UHl0aG9uIGlzIGtpbmQ="));
    EXPECT_EQ("Python is kinda c", Base64::decode("UHl0aG9uIGlzIGtpbmRhIGM="));
    EXPECT_EQ("Python is kinda cool", Base64::decode("UHl0aG9uIGlzIGtpbmRhIGNvb2w="));
}

TEST(Base64DecodeTest, Decode2EqualityString)
{
    EXPECT_EQ("P", Base64::decode("UA=="));
    EXPECT_EQ("Pasc", Base64::decode("UGFzYw=="));
    EXPECT_EQ("Pascal ", Base64::decode("UGFzY2FsIA=="));
    EXPECT_EQ("Pascal is ", Base64::decode("UGFzY2FsIGlzIA=="));
    EXPECT_EQ("Pascal is a p", Base64::decode("UGFzY2FsIGlzIGEgcA=="));
    EXPECT_EQ("Pascal is a piec", Base64::decode("UGFzY2FsIGlzIGEgcGllYw=="));
    EXPECT_EQ("Pascal is a piece o", Base64::decode("UGFzY2FsIGlzIGEgcGllY2Ugbw=="));
    EXPECT_EQ("Pascal is a piece of g", Base64::decode("UGFzY2FsIGlzIGEgcGllY2Ugb2YgZw=="));
    EXPECT_EQ("Pascal is a piece of garb", Base64::decode("UGFzY2FsIGlzIGEgcGllY2Ugb2YgZ2FyYg=="));
    EXPECT_EQ("Pascal is a piece of garbage", Base64::decode("UGFzY2FsIGlzIGEgcGllY2Ugb2YgZ2FyYmFnZQ=="));
}

TEST(Base64DecodeTest, DecodeInvalidString)
{
    try
    {
        Base64::decode("UGFzY2FsIGlzIGEgcGllY2Ugb2YgZ2FyYmFnZQ");
    }
    catch(std::length_error error)
    {
        SUCCEED();
    }

    try
    {
        Base64::decode("UHl0aG9uIGlzIGtpbmQ==");
    }
    catch(std::length_error error)
    {
        SUCCEED();
    }

    try
    {
        Base64::decode("Qys");
    }
    catch(std::length_error error)
    {
        SUCCEED();
    }





    try
    {
        Base64::decode(";DA-");
    }
    catch(std::invalid_argument error)
    {
        SUCCEED();
    }
    
    try
    {
        Base64::decode("Fgh=+-jh");
    }
    catch(std::invalid_argument error)
    {
        SUCCEED();
    }

    try
    {
        Base64::decode("lalalalalalalalalalalalalalalalalalalallala><><>");
    }
    catch(std::invalid_argument error)
    {
        SUCCEED();
    }
}

TEST(Base64DecodeTest, DecodeEmptyString)
{
    EXPECT_EQ("", Base64::decode(""));
}

TEST(Base64CombinedTest, Base64CombinedTest)
{
    EXPECT_EQ("Ol1QKpeNny9WL", Base64::decode(Base64::encode("Ol1QKpeNny9WL")));
    EXPECT_EQ("UVZlbVJJUENod3I1ag==", Base64::encode(Base64::decode("UVZlbVJJUENod3I1ag==")));

    EXPECT_EQ("TIWPrA8HxYJQr", Base64::decode(Base64::encode(Base64::decode(Base64::encode("TIWPrA8HxYJQr")))));
    EXPECT_EQ("UTZNSVVmR0xnTUtJdg==", Base64::encode(Base64::decode(Base64::encode(Base64::decode("UTZNSVVmR0xnTUtJdg==")))));
}