data = []
columns = []
datafile = open("data.csv", "r")

# Obtaining the columns
columns = [i.replace(" ","").replace("\n","").lower() for i in datafile.readline().split(',')]

# Obtaining the data
# Splitting the string with ',' as delimiter
# |->Trimming The string
#    |-> Removing newlines from string
for line in datafile:
    dataList = list(line.split(','))
    dataList = [i.replace(" ","").replace("\n","").lower() for i in dataList]
    data.append(dataList)

result_index = int(input("Enter the Index of Label > "))

target_data = []

for column in columns:
    if column != columns[result_index]:
        target_data.append(input("Specify the '" + column + "' > "))

answer_set = set()

for x in data:
    answer_set.add(x[result_index])

# data contains input data
# answer_set = ('yes', 'no')

conditional_probabilities = dict()
posterior_probabilities = dict()

for x in answer_set:
    posterior_probabilities[x] = 1
    conditional_probabilities[x] = 1
# conditional_probabilities = ( {"yes": 1}, {"no": 1})

# color | type | origin
for i in range(0, len(target_data)):
    individual_count = {}
    individual_total = {}

    # individual_count = ( {"yes": 0}, {"no": 0} )
    for x in answer_set:
        individual_count[x] = 0
        individual_total[x] = 0

    total = 0
    # Iterating through data
    # Get target count && total Count
    for j in range(0, len(data)):
        # Check if column value matches with target value
        if (target_data[i] == data[j][i]):      
             # Add Count to respective soln bucket
             individual_count[data[j][result_index]] += 1
        individual_total[data[j][result_index]] += 1

    for result in answer_set:
        conditional_probabilities[result] *= (individual_count[result] / individual_total[result])
        print(target_data[i] + " " + result + ": " + str(individual_count[result]) + " / " + str(individual_total[result]))

min = -1
final_result = ""

for result in conditional_probabilities.keys():

    # PRIOR PROBABILITY Calculation
    count = 0
    total = 0
    for x in data:
        total += 1
        if x[result_index] == result:
            count += 1
    prior_probability = count / total

    posterior_probabilities[result] = conditional_probabilities[result] * prior_probability
    print(result + " = " + str(posterior_probabilities[result]))

    if posterior_probabilities[result] > min or min == -1:
        min = posterior_probabilities[result]
        final_result = result

target_data.insert(result_index, final_result)

print("Result: " + final_result)

with open('data.txt', 'a') as f:
    f.write("\n" + ",".join(target_data))