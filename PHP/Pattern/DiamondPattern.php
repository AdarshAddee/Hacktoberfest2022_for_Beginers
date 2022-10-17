//  Github username: DarkAk007
// Aim: Print a DiamondPattern using PHP
// Date: 18-10-2022

// start coding

<?php
function print_pattern($num)
{
// The Upper Half Pattern
// Outer loop handles number of rows
for ($i = 0; $i < $num; $i++)
{
// inner loop handles indentation
for($k = $num; $k > $i+1; $k-- )
{
// Print spaces
echo " ";
}
// inner loop handles number of stars
for($j = 0; $j <= $i; $j++ )
{
// Print stars
echo "* ";
}
// go to new line after each row pattern is printed
echo "\n";
}
// The Lower Half Pattern
// Outer loop handles number of rows
for ($i = $num-1; $i > 0; $i--)
{
// inner loop handles indentation
for($k = $num-1; $k >= $i; $k-- )
{
// Print spaces
echo " ";
}
// inner loop handles number of stars
for($j = 0; $j < $i; $j++ )
{
// Print stars
echo "* ";
}
// go to new line after each row pattern is printed
echo "\n";
}
}
//Call function and send number of lines as parameter
$num = 5;
print_pattern($num);
?>