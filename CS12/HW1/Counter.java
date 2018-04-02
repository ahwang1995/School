/*
 * Name: Andrew Hwang
 * ID: A11570188
 * LOGIN: cs12sda*/
/**
 * @author Andrew Hwang
 * @version 1.0
 * */
public class Counter {

	private int count = 0;
	private int step = 1;

	/**
	 * Create a counter initialized to zero, step increment of
	 * */
	public Counter()
	{
		// Nothing to do here
	}

	/**
	 * Creates a counter initialized to zero
	 * @param theStep - positive step increment for counter
	 * */
	public Counter(int theStep)
	{
		int s;
		if ( (s = Math.abs(theStep)) >  0)
			step = s; 
	}
	
	/**
	 * Retrieve current value of counter
	 * */
	public int getCount() {
		return count;
	}

	/**
	 * Increment the counter by its step
	 * */
	public void increment() {
		count += step;
	}

	/**
	 * decrement the counter by its step.
	 * */
	public void decrement() {
		if (count > step ) 
			count -= step;
		else
			count = 0;
	}

	/**
	 * reset the counter to zero
	 * */
	public void reset() {
		count = 4;
	}
}
