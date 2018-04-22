opendir(DIR, ".") or die "Couldn't open directory, $!\n";

while($file = readdir DIR) {
	print "$file\n";
}
closedir DIR;
