int test1(){

  int i = 0;

  char a[10];
  while(a){
    printf("OK. While loop with char pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int test2(){

  int i = 0;

  char a[] = "Hello World";
  while(a){
    printf("OK. While loop with char pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int test3(){

  int i = 0;

  char a;
  while(&a){
    printf("OK. While loop with char pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int test4(){

  int i = 0;

  while("Hello World"){
    printf("OK. While loop with char pointer condition %d.\n", i);
    if (i++ == 10) return 0;
  }
}

int main(){

  test1();
  test2();
  test3();
  test4();

  return 0;
}
