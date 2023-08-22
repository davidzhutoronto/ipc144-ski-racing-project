X-Country Ski Race Reporting Program
====================================

This program focuses on processing data from a cross-country ski race. The program reads information from a text file, processes the data, and provides various reporting options based on user input.

Functionalities
---------------

The program offers the following functionalities through a menu-driven interface:

-   Display the best 3 skiers in a distance category: Lists the fastest completed times for the top 3 skiers in a selected distance category.
-   Display all skiers in a distance category: Displays details of all skiers within a chosen distance category.
-   Display the worst 3 skiers in a distance category: Shows the slowest completed times for the last 3 skiers in a selected distance category.
-   Display the winners in all distance categories: Presents the winners of each distance category.
-   Exit the application: Quits the program.

Sample Output
-------------

Here's a sample execution of the program with user input and corresponding outputs:

```
`************** X-Country Ski Race Reporting **************
What would you like to do?
0 - Exit
1 - Print top 3 skiers in a category
2 - Print all skiers in a category
3 - Print last 3 skiers in a category
4 - Print winners in all categories
: 1

Which category (S, M, L): S

Skier           Age Group   Time
Angus Young     Senior      1:50
Eddie Van Halen Senior      2:35
Billy F. Gibbons Senior     3:08

What would you like to do?
0 - Exit
1 - Print top 3 skiers in a category
2 - Print all skiers in a category
3 - Print last 3 skiers in a category
4 - Print winners in all categories
: 4

Skier           Age Group   Category   Time
Angus Young     Senior      10 km      1:50
Eddy Mercx      Senior      25 km      1:48
Cecilie Ledwig  Adult       50 km      1:38

What would you like to do?
0 - Exit
1 - Print top 3 skiers in a category
2 - Print all skiers in a category
3 - Print last 3 skiers in a category
4 - Print winners in all categories
: 0

Keep on Skiing!`
```

Additional Information
----------------------

-   The program follows modular programming to enhance code organization and readability.
-   It efficiently manages repetitive distance categories and age groups to optimize memory usage.
-   The `readFileRecord()` function handles varying field counts on each line (record) by using a specific data format.

