#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_fibonacci_series_it_produce_series_upto_5_term,test_concanate_array1_array2__as_result_array_1_2_2_3,test_filter_should_give_100_and_90_from_array_100_90_80,test_reverse_the_array_scores_as_42_12_54_43_23,test_slice_the_array1_which_gives_the_array_from_the_indexof_2_to_5,test_slice_the_array1_which_gives_the_array_from_0_to_3_if_slice_with_minus_6_4,test_give_the_4_numberOfprimes_between_1_to_10,test_give_the_168_numberOfprimes_between_2_to_1000,test_give_the_669_numberOfprimes_between_2_to_5000,test_give_the_1754_numberOfprimes_between_2_to_15000,test_gives_the_hello_and_hello_are_same,test_gives_the_reja_and_rani_are_not_same,test_gives_helloooo_and_hello_difference_is_111,test_it_prints_1_2_3_4_5,test_it_prints_a_b_c_d,test_filter_return_5_6_7_from_the_array,test_filter_return_lenth_3_after_filter_the_array,test_map_returns_the_value_after_multiplyby2_of_each_element,test_map_return_lenth_6_after_and_change_hiiiii_string_by_hmmmmm,test_floatmap_returns_the_value_after_multiplyby2_of_each_element,test_reduce_will_return_20,test_reduceString_it_retunr_the_concanate_string_TThihihihehe,test_reduceString_it_return_the_maxLength_string_parmatma,test_reduceChar_it_returns_string_Thello,test_indexOf_will_return_the_2_index_of_r,test_stringindexOf_will_return_the_2_index_of_rma,test_stringindexOf_will_return_the_3_index_of_ram,test_stringindexOf_will_return_the_3_index_of_ma;
Test test[] = {"test_fibonacci_series_it_produce_series_upto_5_term",test_fibonacci_series_it_produce_series_upto_5_term,"test_concanate_array1_array2__as_result_array_1_2_2_3",test_concanate_array1_array2__as_result_array_1_2_2_3,"test_filter_should_give_100_and_90_from_array_100_90_80",test_filter_should_give_100_and_90_from_array_100_90_80,"test_reverse_the_array_scores_as_42_12_54_43_23",test_reverse_the_array_scores_as_42_12_54_43_23,"test_slice_the_array1_which_gives_the_array_from_the_indexof_2_to_5",test_slice_the_array1_which_gives_the_array_from_the_indexof_2_to_5,"test_slice_the_array1_which_gives_the_array_from_0_to_3_if_slice_with_minus_6_4",test_slice_the_array1_which_gives_the_array_from_0_to_3_if_slice_with_minus_6_4,"test_give_the_4_numberOfprimes_between_1_to_10",test_give_the_4_numberOfprimes_between_1_to_10,"test_give_the_168_numberOfprimes_between_2_to_1000",test_give_the_168_numberOfprimes_between_2_to_1000,"test_give_the_669_numberOfprimes_between_2_to_5000",test_give_the_669_numberOfprimes_between_2_to_5000,"test_give_the_1754_numberOfprimes_between_2_to_15000",test_give_the_1754_numberOfprimes_between_2_to_15000,"test_gives_the_hello_and_hello_are_same",test_gives_the_hello_and_hello_are_same,"test_gives_the_reja_and_rani_are_not_same",test_gives_the_reja_and_rani_are_not_same,"test_gives_helloooo_and_hello_difference_is_111",test_gives_helloooo_and_hello_difference_is_111,"test_it_prints_1_2_3_4_5",test_it_prints_1_2_3_4_5,"test_it_prints_a_b_c_d",test_it_prints_a_b_c_d,"test_filter_return_5_6_7_from_the_array",test_filter_return_5_6_7_from_the_array,"test_filter_return_lenth_3_after_filter_the_array",test_filter_return_lenth_3_after_filter_the_array,"test_map_returns_the_value_after_multiplyby2_of_each_element",test_map_returns_the_value_after_multiplyby2_of_each_element,"test_map_return_lenth_6_after_and_change_hiiiii_string_by_hmmmmm",test_map_return_lenth_6_after_and_change_hiiiii_string_by_hmmmmm,"test_floatmap_returns_the_value_after_multiplyby2_of_each_element",test_floatmap_returns_the_value_after_multiplyby2_of_each_element,"test_reduce_will_return_20",test_reduce_will_return_20,"test_reduceString_it_retunr_the_concanate_string_TThihihihehe",test_reduceString_it_retunr_the_concanate_string_TThihihihehe,"test_reduceString_it_return_the_maxLength_string_parmatma",test_reduceString_it_return_the_maxLength_string_parmatma,"test_reduceChar_it_returns_string_Thello",test_reduceChar_it_returns_string_Thello,"test_indexOf_will_return_the_2_index_of_r",test_indexOf_will_return_the_2_index_of_r,"test_stringindexOf_will_return_the_2_index_of_rma",test_stringindexOf_will_return_the_2_index_of_rma,"test_stringindexOf_will_return_the_3_index_of_ram",test_stringindexOf_will_return_the_3_index_of_ram,"test_stringindexOf_will_return_the_3_index_of_ma",test_stringindexOf_will_return_the_3_index_of_ma};
char testFileName[] = {"myTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}