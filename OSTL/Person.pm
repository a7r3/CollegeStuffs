package Person;

sub new {
	my $class = shift;
	my $self = {
		_firstName => shift,
		_lastName => shift,
		_ssn => shift,
	};

	print "First Name -> $self->{_firstName}\n";
	print "Last Name -> $self->{_lastName}\n";
	print "SSN -> $self->{_ssn}\n";
	bless $self, $class;
	return $self;
}

# Getter and Setter for FirstName

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
