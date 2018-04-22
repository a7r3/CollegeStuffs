package Person;

# 'new' doesn't necessarily indicate a constructor
# Other names could be used. It is a OO convention you know.
# Subroutines with the 'blessing' are valid constructors in Perl
sub new {
	# shift keyword removes the first argument from @_
	# and gives it to the variable to which it is assigned	
	# This variable holds the Class' name
	my $class = shift;
	# Constructing a hash table
	my $self = {
		_firstName => shift,
		_lastName => shift,
		_ssn => shift,
	};

	print "First Name -> $self->{_firstName}\n";
	print "Last Name -> $self->{_lastName}\n";
	print "SSN -> $self->{_ssn}\n";
	# Associating the hash-table (object) before with the ClassName
	# Thus, when we try to create an Object of 'Person', then this hash-table (Object) is returned
	bless $self, $class;
	# Returning the created Object
	return $self;
}

# Getter and Setter subroutines for 'firstName'
sub setFirstName {
	my( $self, $firstName ) = @_;
	$self->{_firstName} = $firstName if defined($firstName);
	return $self->{_firstName};
}

sub getFirstName {
	my( $self ) = @_;
	return $self->{_firstName};
}

# Return 1 at the end of this file
# Reports to the compiler that Instance creation has been successfully made
1;
