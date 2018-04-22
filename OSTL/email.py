import re

# Valid Email Criteria
# * Starts with Small Alphabet
# * Can contain alphanumeric (except CAPITALS), underscore (_), and dot (.)
# * An '@' which seperates the unique id and domain id
# * The Domain ID, which may be one of the possible domains
email_pattern = '^[a-z][a-z0-9_\.]+@\w+[\.]{0,1}\w{2,3}[\.]{0,1}[\w]{2,3}'

with open("mail.txt","r") as f:
	print("\nValid E-mail IDs are\n");
	for line in f:
		normal_match = re.search(email_pattern,line)
		if normal_match:
			print(normal_match.group())
