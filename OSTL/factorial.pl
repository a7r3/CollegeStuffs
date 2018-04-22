$number = 4;

$fact = 1;

for($i = 1; $i <= $number; $i++) {
	$fact = $fact * $i;
}

print "\nFactorial of $number is : $fact";

print "\nEnter number to calculate factorial\n";

$num = <>;
$f = 1;
for($i = 1; $i <= $num; $i++) {
	$f = $f * $i;
}

print "\nFactorial of $num is $f"
