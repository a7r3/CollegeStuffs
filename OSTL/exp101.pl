use Person;

# Instantiating a 'Person' object
$object = new Person("John", "Doe", 34324857);

# Get the FirstName via the getter
$firstName = $object->getFirstName();

print "First Name (before setting) : $firstName\n";

# Set the FirstName with the Setter
$object->setFirstName("Some");

# Get the updated FirstName
$firstName = $object->getFirstName();

print "First Name (after setting) : $firstName\n";
