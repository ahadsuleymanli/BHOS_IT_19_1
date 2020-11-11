## Lab asignment for week9
implement the function parseNums() that outputs two char arrays separately  
one made out of numbers and the other non numbers.

```c
void parseNums(char *source, char *integers, char *nonInteger);
int main()
{
  char source[] = "abc123def99!";
  char integers[256];
  char nonIntegers[256];
  parseNums(source, integers, nonIntegers);
  // output shud be: abcdef!, 12399
}
```
