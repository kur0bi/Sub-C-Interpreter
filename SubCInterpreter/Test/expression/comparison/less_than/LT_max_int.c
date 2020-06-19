int int_fun(){

  return 0;
}

char char_fun(){

  return 'a';
}

int test(){

  int int_var = 1;
  char char_var = 1;
  int int_array[3] = {1,2,3};
  char char_array[3] = {1,2,3};

  int value;

  value = 2147483647 < 10;
  printf("OK. Max int less than costant positive comparison. Value %d.\n", value);

  value = 2147483647 < -1;
  printf("OK. Max int less than costant negative integer comparison. Value %d.\n", value);

  value = 2147483647 < int_var;
  printf("OK. Max int less than variable integer comparison. Value %d.\n", value);

  value = 2147483647 < char_var;
  printf("OK. Max int less than variable char comparison. Value %d.\n", value);

  value = 2147483647 < int_array[1];
  printf("OK. Max int less than int array element comparison. Value %d.\n", value);

  value = 2147483647 < char_array[1];
  printf("OK. Max int less than char array element comparison. Value %d.\n", value);

  value = 2147483647 < 'a';
  printf("OK. Max int less than costant char comparison. Value %d.\n", value);

  value = 2147483647 < int_fun();
  printf("OK. Max int less than int function call comparison. Value %d.\n", value);

  value = 2147483647 < char_fun();
  printf("OK. Max int less than char function call comparison. Value %d.\n", value);

  value = 2147483647 < (1+1*10/10%10);
  printf("OK. Max int less than costant operation comparison. Value %d.\n", value);

  value = 2147483647 < ++int_var;
  printf("OK. Max int less than pre increment comparison. Value %d.\n", value);

  value = 2147483647 < --int_var;
  printf("OK. Max int less than pre decrement comparison. Value %d.\n", value);

  value = 2147483647 < int_var++;
  printf("OK. Max int less than post increment comparison. Value %d.\n", value);

  value = 2147483647 < int_var--;
  printf("OK. Max int less than post decrement comparison. Value %d.\n", value);

  value = 2147483647 < (1 && 1)||(10 > 5)||(10 < 5)||(10 == 10)||(10 != 20);
  printf("OK. Max int less than costant comparisons comparison. Value %d.\n", value);

  return 0;
}

int main(){

  test();

  return 0;
}
