
import sys

def merge_and_count_splitinv(array):
  if len(array) == 1:
    return (0, array)
  elif len(array) == 2:
    if array[0] > array[1]:
      array.inverse()
      return (1, array)
    else:
      return (0, array)
  split_inv_count = 0
  i=0
  j=0
  left_half = array[:len(array)/2]
  right_half = array[len(array)/2:]
  sorted_array = []
  for k in range(len(array)):
    #Check if i/j has reached the limit
    if i == len(left_half):
      #Copy right_half to sorted_array
      sorted_array += right_half[j:]
      break
    if j == len(right_half):
      #Copy left_half to sorted_array
      sorted_array += left_half[i:]
      break
    if left_half[i] <= right_half[j]:
      sorted_array.append(left_half[i])
      i += 1
    elif left_half[i] > right_half[j]:
      count += (len(left_half)-i)
      sorted_array.append(right_half[j])
      j += 1
  return (count, sorted_array)

def sort_and_count(array):
  # Sorts the array and counts the inversions
  if len(array) <= 1:
    return (0, array)
  (x, sorted_left_subarray) = sort_and_count(array[:len(array)/2])
  (y, sorted_right_subarray) = sort_and_count(array[len(array)/2:]
  (z, sorted_array) = merge_and_count_splitinv(sorted_left_subarray + sorted_right_subarray)
  return (x+y+z, sorted_array)

def main():
  input_file = open('./array.txt','r')
  array = [i.strip() for i in input_file.readlines()]
  print array[:10]
  print sort_and_count(array)

if __name__ == "__main__":
  main()
