#include "gtest/gtest.h"
#include "student.h"
#include <cmath>

TEST(StudentTest, HandlesDefaultConstructor) { // testuoja default konstruktoriu
    Student s;
    EXPECT_EQ(s.getFirstName(), "");
    EXPECT_EQ(s.getLastName(), "");
    EXPECT_EQ(s.getExamResults(), 0);
}

TEST(StudentTest, HandlesParameterizedConstructor) { // testuoja konstruktoriu su parametrais
    Student s("Jonas", "Kazlauskas", 10, {7, 8, 9});
    EXPECT_EQ(s.getFirstName(), "Jonas");
    EXPECT_EQ(s.getLastName(), "Kazlauskas");
    EXPECT_EQ(s.getExamResults(), 10);
    EXPECT_EQ(s.getHomeworkResults(), std::vector<int>({7, 8, 9}));
}

TEST(StudentTest, HandlesCopyConstructor) { // testuoja copy konstruktoriu
    Student s1("Jonas", "Kazlauskas", 10, {7, 8, 9});
    Student s2(s1);
    EXPECT_EQ(s2.getFirstName(), "Jonas");
    EXPECT_EQ(s2.getLastName(), "Kazlauskas");
    EXPECT_EQ(s2.getExamResults(), 10);
    EXPECT_EQ(s2.getHomeworkResults(), std::vector<int>({7, 8, 9}));
}

TEST(StudentTest, HandlesMoveConstructor) { // testuoja move konstruktoriu
    Student s1("Jonas", "Kazlauskas", 10, {7, 8, 9});
    Student s2(std::move(s1));
    EXPECT_EQ(s2.getFirstName(), "Jonas");
    EXPECT_EQ(s2.getLastName(), "Kazlauskas");
    EXPECT_EQ(s2.getExamResults(), 10);
    EXPECT_EQ(s2.getHomeworkResults(), std::vector<int>({7, 8, 9}));
}

TEST(StudentTest, HandlesAssignmentOperator) { // testuoja priskyrimo operatoriu
    Student s1("Jonas", "Kazlauskas", 10, {7, 8, 9});
    Student s2;
    s2 = s1;
    EXPECT_EQ(s2.getFirstName(), "Jonas");
    EXPECT_EQ(s2.getLastName(), "Kazlauskas");
    EXPECT_EQ(s2.getExamResults(), 10);
    EXPECT_EQ(s2.getHomeworkResults(), std::vector<int>({7, 8, 9}));
}

TEST(StudentTest, HandlesMoveAssignmentOperator) { // testuoja move priskyrimo operatoriu
    Student s1("Jonas", "Kazlauskas", 10, {7, 8, 9});
    Student s2;
    s2 = std::move(s1);
    EXPECT_EQ(s2.getFirstName(), "Jonas");
    EXPECT_EQ(s2.getLastName(), "Kazlauskas");
    EXPECT_EQ(s2.getExamResults(), 10);
    EXPECT_EQ(s2.getHomeworkResults(), std::vector<int>({7, 8, 9}));
}

TEST(StudentTest, HandlesCalculateAverage) { // testuoja calculateAverage metoda
    Student s("Jonas", "Kazlauskas", 10, {7, 8, 9});
    EXPECT_DOUBLE_EQ(s.calculateAverage(), 8.0);
}

TEST(StudentTest, HandlesCalculateMedian) { // testuoja calculateMedian metoda
    Student s("Jonas", "Kazlauskas", 10, {7, 8, 9});
    EXPECT_DOUBLE_EQ(s.calculateMedian(), 8.0);
}

TEST(StudentTest, HandlesCalculateFinalGrade) { // testuoja calculateFinalGrade metoda
    Student s("Jonas", "Kazlauskas", 10, {7, 8, 9});
    EXPECT_EQ(s.calculateFinalGrade(false), 9.2);
    EXPECT_EQ(s.calculateFinalGrade(true), 9.2);
}