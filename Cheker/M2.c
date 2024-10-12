/*
#define _CRT_SECURE_NO_WARNINGS
#define CLOCK_PER_SEC

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



double make_random_number(double min_ch, double max_ch, int sid_variable)
{
  double zero_one = 0, random_number = 0, zero_max_ch = 0;
  int randomization = 0;
  srand(clock() + sid_variable * 1000);
  randomization = rand();
  zero_one = (double)randomization / RAND_MAX;
  zero_max_ch = zero_one * (max_ch - min_ch);
  random_number = zero_max_ch + min_ch;
  return random_number;
}


int make_dec_remain(double double_variable)
{
  double remain = 0;
  int int_remain = 1;
  if (double_variable >= 0)
  {
    remain = double_variable - floor(double_variable);
  }
  else
    remain = (-double_variable) + ceil(double_variable);
  remain *= 1000000;
  int_remain = (int)round(remain);
  return int_remain;
}


int main()
{
  double random_number = 0, min_ch = 0, max_ch = 0, result = 0, number = 0;
  int count_of_numbers = 0, counter = 0, index_of_massive = 0, dec_remain, index, index_for_encoder;
  char first_massive_of_remains[250000], second_massive_of_remains[250000];
  char third_massive_of_remains[250000], fourth_massive_of_remains[250000];
  char num_for_encoding;
  FILE* file_of_numbers;
  for (counter; counter < 250000; counter++)
  {
    first_massive_of_remains[counter] = 20;
    second_massive_of_remains[counter] = 20;
    third_massive_of_remains[counter] = 20;
    fourth_massive_of_remains[counter] = 20;
  }
  file_of_numbers = fopen("stor.txt", "r");
  count_of_numbers = 1000000;
  for (counter = 0; counter < count_of_numbers; counter++)
  {
    fscanf(file_of_numbers, "%lf\n", &number);
    dec_remain = make_dec_remain(number);
    if (dec_remain >= 0 && dec_remain < 250000)
    {
      first_massive_of_remains[dec_remain] = 10;
    }
    else if (dec_remain >= 250000 && dec_remain < 500000)
    {
      second_massive_of_remains[dec_remain - 250000] = 10;
    }
    else if (dec_remain >= 500000 && dec_remain < 750000)
    {
      third_massive_of_remains[dec_remain - 500000] = 10;
    }
    else
    {
      fourth_massive_of_remains[dec_remain - 750000] = 10;
    }
  }
  fclose(file_of_numbers);


  file_of_numbers = fopen("stor.txt", "r");

  for (counter = 0; counter < count_of_numbers; counter++)
  {
    fscanf(file_of_numbers, "%lf\n", &number);

    if (counter >= 0 && counter < 250000)
    {
      index = first_massive_of_remains[counter];
    }
    else if (counter >= 250000 && counter < 500000)
    {
      index = second_massive_of_remains[counter - 250000];
    }
    else if (counter >= 500000 && counter < 750000)
    {
      index = third_massive_of_remains[counter - 500000];
    }
    else
    {
      index = fourth_massive_of_remains[counter - 750000];
    }
    if (index == 10)
    {
      result -= number;
    }

    else
    {
      result += number;
    }
  }
  fclose(file_of_numbers);


  printf("Result: %lf.\n", result);
}
*/