print "\nOpening file1.txt\n";
open(DATA, "<file1.txt") or die "Can't open data";
print "Contents of file1.txt\n";
@lines = <DATA>;
print @lines;
close(DATA);
print "\nFeeding Contents of file1.txt to DATA_1 Filehandle";
open(DATA_1, "<file1.txt");
print "\nCreating a FileHandle for file2.txt in write mode";
open(DATA_2, ">file2.txt");
print "\nCopying the contents of file1.txt into file2.txt";
while(<DATA_1>){
	print DATA_2 $_;
}
# Close the file handles
close(DATA_1);
close(DATA_2);
