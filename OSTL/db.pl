use DBI;
use strict;
my $driver = "mysql";
my $database = "TESTDB";
my $dsn = "DBI:$driver:database=$database";
my $userid = "root";
my $password = "";
my $dbh = DBI->connect($dsn, $userid, $password) or die $DBI::errstr;

my $sth = $dbh->prepare("CREATE TABLE TEST
	(FIRST_NAME TEXT,
 	LAST_NAME TEXT,
 	SEX TEXT,
 	AGE INTEGER,
 	INCOME TEXT);");


my $insert_query = $dbh->prepare("INSERT INTO TEST VALUES(?, ?, ?, ?, ?);");

my $first_name = "John";
my $last_name = "Doe";
my $sex = "M";
my $income = 50000;
my $age = 30;

$insert_query->execute($first_name, $last_name, $sex, $age, $income) or die $DBI::errstr;
$insert_query->finish();

my $select_query = $dbh->prepare("SELECT * FROM TEST WHERE AGE>20");

$select_query->execute() or die $DBI::errstr;

print "\n\nNumber of rows found : ";
print $select_query->rows;
print "\n\nPersons with Age > 20: \n";
while(my @row = $select_query->fetchrow_array()) {
	my ($first_name, $last_name) = @row;
	print "\nFirst Name - $first_name \n";
	print "Last Name - $last_name \n\n";
}

$select_query->finish();
