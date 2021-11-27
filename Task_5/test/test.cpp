#include "gtest/gtest.h"
#include "Matrix.h"

TEST(MatrixConstructorTest, NotSquareMatrixConstructorTest)
{
    Matrix mtx(5, 6);
    EXPECT_EQ(5, mtx.getRows());
    EXPECT_EQ(6, mtx.getColumns());
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            EXPECT_EQ(0, mtx[i][j]);
        }
    }

    try
    {
        Matrix mtx2(0, 5);
    }
    catch(SizeException error)
    {
        SUCCEED();
    }
    catch(...)
    {
        FAIL();
    }

    try
    {
        Matrix mtx2(-3, 5);
    }
    catch(SizeException error)
    {
        SUCCEED();
    }
    catch(...)
    {
        FAIL();
    }
    
    try
    {
        Matrix mtx2(5, 0);
    }
    catch(SizeException error)
    {
        SUCCEED();
    }
    catch(...)
    {
        FAIL();
    }

    try
    {
        Matrix mtx2(5, -2);
    }
    catch(SizeException error)
    {
        SUCCEED();
    }
    catch(...)
    {
        FAIL();
    }
}

TEST(MatrixConstructorTest, SquareMatrixConstructorTest)
{
    Matrix mtx(5);
    EXPECT_EQ(5, mtx.getRows());
    EXPECT_EQ(5, mtx.getColumns());
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ(0, mtx[i][j]);
        }
    }

    try
    {
        Matrix mtx2(0);
    }
    catch(SizeException error)
    {
        SUCCEED();
    }
    catch(...)
    {
        FAIL();
    }
}

TEST(MatrixConstructorTest, CloneMatrixConstructorTest)
{
    Matrix mtx1(5);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = (i+1) * (j+3);
        }
    }
    Matrix mtx2(mtx1);
    EXPECT_EQ(5, mtx2.getRows());
    EXPECT_EQ(5, mtx2.getColumns());
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ((i+1) * (j+3), mtx2[i][j]);
        }
    }
}

TEST(MatrixByNumberMultiplicationTest, SquareMatrixByNumberMultiplicationTest)
{
    Matrix mtx(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx[i][j] = i;
        }
    }

    Matrix resmtx(mtx * 5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ((i * 5), resmtx[i][j]);
        }
    }
}

TEST(MatrixByNumberMultiplicationTest, NotSquareMatrixByNumberMultiplicationTest)
{
    Matrix mtx(5,6);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mtx[i][j] = i;
        }
    }

    Matrix resmtx(mtx * 5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            EXPECT_EQ((i * 5), resmtx[i][j]);
        }
    }
}

TEST(MatrixByNumberMultiplicationTest, NumberByMatrixMultiplicationTest)
{
    Matrix mtx(5,6);

    int** mtx2 = new int*[5];
    for(int i = 0; i < 5; i++)
    {
        mtx2[i] = new int[6];
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mtx[i][j] = i;
            mtx2[i][j] = i * 5;
        }
    }

    Matrix resmtx1(mtx * 5);

    Matrix resmtx2(5 * mtx);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            EXPECT_EQ(resmtx1[i][j], resmtx2[i][j]);
            EXPECT_EQ(resmtx1[i][j], mtx2[i][j]);
            EXPECT_EQ(resmtx2[i][j], mtx2[i][j]);
        }
    }
}

TEST(MatrixSubstractionTest, SquareMatrixSubstractionTest)
{
    Matrix mtx1(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = i;
        }
    }

    Matrix mtx2(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx2[i][j] = j;
        }
    }

    Matrix resmtx1(mtx1 - mtx2);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ((i - j), resmtx1[i][j]);
        }
    }

    Matrix resmtx2(mtx2 - mtx1);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ((j - i), resmtx2[i][j]);
        }
    }
}

TEST(MatrixSubstractionTest, NotSquareEqualSizeMatrixSubstractionTest)
{
    Matrix mtx1(5, 6);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mtx1[i][j] = i;
        }
    }

    Matrix mtx2(5, 6);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mtx2[i][j] = j;
        }
    }

    Matrix resmtx1(mtx1 - mtx2);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            EXPECT_EQ((i - j), resmtx1[i][j]);
        }
    }

    Matrix resmtx2(mtx2 - mtx1);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            EXPECT_EQ((j - i), resmtx2[i][j]);
        }
    }
}

TEST(MatrixSubstractionTest, NotSquareNotEqualSizeMatrixSubstractionTest)
{
    Matrix mtx1(5, 6);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            mtx1[i][j] = i;
        }
    }

    Matrix mtx2(6, 5);

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx2[i][j] = j;
        }
    }

    bool wasError = false;

    try
    {
        Matrix resmtx1(mtx1 - mtx2);
    }
    catch(SizeException error)
    {
        SUCCEED();
        wasError = true;
    }

    try
    {
        Matrix resmtx2(mtx2 - mtx1);
    }
    catch(SizeException error)
    {
        SUCCEED();
        wasError = true;
    }
    if(!wasError)
    {
        FAIL();
    }
}

TEST(MatrixAverageTest, MatrixAverageTest)
{
    Matrix mtx1(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = i;
        }
    }

    EXPECT_EQ(2, mtx1.average());

    Matrix mtx2(4);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mtx2[i][j] = i+j;
        }
    }

    EXPECT_EQ(3, mtx2.average());

    Matrix mtx3(4, 5);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx3[i][j] = (2 * i) + (3 * j);
        }
    }

    EXPECT_EQ(9, mtx3.average());
}

TEST(MatrixMostUnaverageTest, MatrixMostUnaverageTest)
{
    Matrix mtx1(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = i;
        }
    }

    EXPECT_EQ(0, mtx1.mostUnaverage());

    Matrix mtx2(4);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mtx2[i][j] = i+j;
        }
    }

    EXPECT_EQ(0, mtx2.mostUnaverage());

    Matrix mtx3(4, 5);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx3[i][j] = (2 * i) + (3 * j);
        }
    }

    EXPECT_EQ(0, mtx3.mostUnaverage());
}

TEST(MatrixTransposeTest, MatrixTransposeTest)
{
    Matrix mtx1(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = i;
        }
    }

    Matrix tmtx1(mtx1.transpon());

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ(mtx1[i][j], tmtx1[j][i]);
        }
    }

    Matrix mtx2(4);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mtx2[i][j] = i+j;
        }
    }

    Matrix tmtx2(mtx2.transpon());

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            EXPECT_EQ(mtx2[i][j], tmtx2[j][i]);
        }
    }

    Matrix mtx3(4, 5);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx3[i][j] = (2 * i) + (3 * j);
        }
    }

    Matrix tmtx3(mtx3.transpon());

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ(mtx3[i][j], tmtx3[j][i]);
        }
    }
}

TEST(MirrorBySecondaryDiagonalTest, MirrorBySecondaryDiagonalTest)
{
    Matrix mtx1(5);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mtx1[i][j] = i;
        }
    }

    Matrix mmtx1(mtx1.mirrorSecondary());

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            EXPECT_EQ(mtx1[i][j], mmtx1[mtx1.getRows() - 1 - j][mtx1.getColumns() - 1 - i]);
        }
    }

    Matrix mtx2(4);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mtx2[i][j] = i+j;
        }
    }

    Matrix mmtx2(mtx2.mirrorSecondary());

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            EXPECT_EQ(mtx2[i][j], mmtx2[mtx2.getRows() - 1 - j][mtx2.getColumns() - 1 - i]);
        }
    }

    Matrix mtx3(3);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mtx3[i][j] = (2 * i) + (3 * j);
        }
    }

    Matrix mmtx3(mtx3.mirrorSecondary());

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            EXPECT_EQ(mtx3[i][j], mmtx3[mtx3.getRows() - 1 - j][mtx3.getColumns() - 1 - i]);
        }
    }
}