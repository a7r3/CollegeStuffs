# Calculator
# ask first no
# ask second no
# ask for operator
# answer pls

print('Enter the first number');
n1 = raw_input();
print('Enter the second number');
n2 = raw_input();
print('Specify the operation to be performed');
op = raw_input();
if op == '+':
    result = int(n1)+int(n2)
elif op == '-':
    result = int(n1)-int(n2)
elif op == '*':
    result = int(n1)*int(n2)
elif op == '/':
    result = int(n1)/int(n2)
print result
