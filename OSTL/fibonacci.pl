print "Fibonacci Series Limit > ";
$n = <STDIN>;
$a = 0;
$b = 1;

$c = $a + $b;

print "\n$a\t$b\t$c";

while(1) {
	$a = $b;
	$b = $c;
	$c = $a + $b;
	if($c > $n) {
		last;
	}
	print "\t$c";
}
