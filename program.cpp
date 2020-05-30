#include "splashkit.h"

#define VALUE 100

void sketch_value(const int value[], int size)
{
  int x = 0;
  int y;
  int rectangle_height;
  int rectangle_width = screen_width()/size;

  for (int i = 0; i < size; i++)
  {
     rectangle_height = value[i];
     y = screen_height() - rectangle_height;

     fill_rectangle(COLOR_ORANGE, x, y, rectangle_width, rectangle_height);
     draw_rectangle(COLOR_BLACK, x, y, rectangle_width, rectangle_height);
     x += rectangle_width;

  }
}

void draw_sort( int value[], int size)
{
    clear_screen(COLOR_WHITE);
    sketch_value(value, size);
    refresh_screen(60);
}

void array_rnd(int value[], int size)
{
    for (int i = 0; i < size; i++)
    {
        value[i] = rnd(screen_height()) + 1;
    }
}

void swapping(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void bubble_sort(int value[], int size)
{
    for (int a = 0; a < size; a++)
    {
       for (int i =0; i < size - 1; i++)
       {
           if (value[i] > value[i + 1])
           {
               swapping(value[i], value [i + 1]);
               draw_sort(value, size);
           }
       }
    }
}

void selection_sort(int value[], int size)
{
    int a, i;
    for(i = 0; i < size - 1; i++)
    {
        for( a = 1; a< size; a++)
        {
            if (value[a] < value[i])
            {
                swapping(value[a], value[i]);
                draw_sort(value, size);
            }
        }
    }
}

void handle_input(int value[], int size)
{
    if(key_typed(C_KEY))
    {
        array_rnd(value, size);
    }
    else if(key_typed(D_KEY))
    {
        bubble_sort(value, size);
    }
    else if(key_typed(E_KEY))
    {
        selection_sort(value, size);
    }
}


int main()
{
    int value[VALUE];
    open_window("Sort Vis", 800, 600);
    array_rnd(value, VALUE);

    while(not quit_requested())
    {
      process_events();
      handle_input(value, VALUE);
      draw_sort(value, VALUE);
    }
    
    return 0;
}


// Selection sort is used to arrange the numbers in ascending order. However, as selection sort uses separation between sorted and unsorted array, it uses counter shift instead of repetition of passes. This makes selection sort fast.
//The selection sort compares each element with the next. It swaps the values according to the minimum and place it at the beginning. The comparing continues for the full array till the order is ascending and all numbers are in the sorted array.