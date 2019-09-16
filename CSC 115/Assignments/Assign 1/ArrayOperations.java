import java.lang.Math;

/*
 * ArrayOperations
 * DO NOT use builtin java Arrays mehthods
 * A class with basic array methods to
 *  - print the values in an array
 *  - calculate the product of the values in an array
 *  - calculate the minimum of the values in an array
 *  - calculate the maximum of the values in an array
 *  - determine the equality to 2 arrays
 *  -
 *
 */
public class ArrayOperations {
    /*
     * printArray
     *
     * Purpose: prints all the values in the array to the console
     *  example format:  {1,2,3,4}
     *
     * Parameters: an array of integers
     *
     * Returns: void
     *
     */
    public static void printArray ( int[] array ) {
        System.out.print("{");
        for(int i=0; i<array.length; i++) {

            System.out.print(array[i]);
            if(i<array.length-1)
                System.out.print(",");
        }

        System.out.println("}");
    }

    /*
     * arrayProduct
     *
     * Purpose: computes the product of all values in the input array
     *  NOTE: product of 3 numbers n1, n2 and n3 = n1*n2*n3
     *  NOTE: product of no numbers = 1
     *
     * Parameters: an array of integers
     *
     * Returns: product of all values in the array
     *
     */
    public static int arrayProduct ( int[] array ) {
        int product = 1;

        // TODO...
        if(array.length ==0){
            product =1;
        }
        else{
            for(int i=0;i<array.length;i++){
                product*=array[i];
            }

        }

        return product;
    }

    /*
     * arrayMax
     *
     * Purpose: finds the maximum value in the input array
     *
     * Parameters: an array of integers
     *
     * Preconditions:
     *	array contains at least one element
     *
     * Returns: maximum value in the array
     *
     */
    public static int arrayMax (int[] a) {
    // TODO...
        int maxval = a[0];
        if(a.length>=2){
            for(int i=1;i<a.length;i++){
                if(a[i]>maxval){
                    maxval =a[i];
                }
            }
        }
        return maxval;
    }
    
    /*
     * arrayMin
     *
     * Purpose: finds the maximum value in the input array
     *
     * Parameters: an array of integers
     *
     * Preconditions:
     *	array contains at least one element
     *
     * Returns:  minimum value in the array
     *
     */
    public static int arrayMin (int[] a) {
    // TODO...
        int minval = a[0];
        if(a.length>=2){
            for(int i=1;i<a.length;i++){
                if(a[i]<=minval){
                    minval =a[i];
                }
            }
        }
        return minval;
    }

    /*
     * arraysEqual
     *
     * Purpose: determines whether the two arrays are equal
     *      where equal means array1 and array2 are the same length
     *      and the contain the same values in the same order
     *
     * Parameters: two arrays of integers
     *
     * Returns: true if the are equal, false otherwise
     *
     */
    public static boolean arraysEqual (int[] a, int[] b) {
        // NOTE:
        // Because there are only two possible return values
        // from this function, this stub actually passes some
        // of the tests.
        // 
        // However, you will not receive those marks unless you
        // change this code to meet the specifications above.
        //

        if(a.length == b.length){
            if(a.length==0){
                return true;
            }
            else{
                for(int i=0;i<a.length;i++){
                    if(a[i]!=b[i]){
                        return false;
                    }
                }
                return true;
            }
        }
        else{
            return false;
        }
        
    }

    /*
     * shiftLeft
     *
     * Purpose: copies every element in the array into a new array of the same length
     *  with every element shifted by the left by the specified amount
     *
     * Parameters: an input array of integers, 
     *   and the number of positions to shift left by
     *
     * Returns: int[] - the new array
     *
     */
    public static int[] shiftLeft (int[] a, int pos) {
        // TODO...

        int[] arr = new int[a.length];
        if(a.length<=1){
            for(int i=0;i<a.length;i++){
                arr[i] = a[i];
            }
            
        }
        else{
            pos = pos%a.length;
            for(int i=0;i<a.length;i++){
                if(i<pos){

                    arr[a.length-pos+i] = a[i];

                }
                else{
                    arr[i-pos] = a[i];
                }
            }

        }
        return arr;
    }
}
