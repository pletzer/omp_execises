add_executable(ex2 ex2.cxx)
add_executable(ex2b ex2b.cxx)

set(NUM_STEPS 1000000000)

add_test(NAME ex2_1 
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_1
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=1)

add_test(NAME ex2_2
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_2
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=2)

add_test(NAME ex2_4
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_4
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=4)
add_test(NAME ex2_8
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=8)

add_test(NAME ex2_20
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=20)

add_test(NAME ex2_100
         COMMAND ex2 ${NUM_STEPS})
set_tests_properties(ex2_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=100)

add_test(NAME ex2b_1 
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_1
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=1)

add_test(NAME ex2b_2
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_2
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=2)

add_test(NAME ex2b_4
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_4
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=4)
add_test(NAME ex2b_8
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=8)

add_test(NAME ex2b_20
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=20)

add_test(NAME ex2b_100
         COMMAND ex2b ${NUM_STEPS})
set_tests_properties(ex2b_8
                     PROPERTIES ENVIRONMENT OMP_NUM_THREADS=100)
