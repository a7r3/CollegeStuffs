$dir = "/tmp";
my @files = glob( $dir );

foreach( @files ) {
	print"Files\n".@files;
	print $_."\n";
}
print "\n---\n";

$dir = "*.pl";
my @files = glob( $dir );
foreach( @files ) {
	print $_."\n"
}

$dir = "~/.*";
@files = glob( $dir );
foreach( @files ) {
	print $_."\n";
}


