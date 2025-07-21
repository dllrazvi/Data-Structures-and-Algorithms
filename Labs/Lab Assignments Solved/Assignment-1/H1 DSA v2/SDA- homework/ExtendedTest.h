#pragma once

class ExtendedTest {
public:
    // Constructor
    ExtendedTest();

    // Method to run all tests for the extended functionality
    void runTests();

private:
    // Private helper methods for individual test cases
    void test1();
    void test2();
    void test3();

    // Add additional test methods as needed
};

// Function to run all tests for the extended functionality
void testAllExtended();