import java.util.*;
import java.text.DecimalFormat;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda
Date: 6/4/14*/
public class Quantity {

	/**member variables to store the numerical value
	 * and a map to store the variables
	 */
	private double value;
	private Map<String,Integer> unit;
	
	//no-arg constructor
	public Quantity()
	{
		value = 1.0;
		unit = new HashMap<String,Integer>();
	}
	/**Copy constructor that makes a new quantity with the same
	 * values as q
	 * @param q
	 */
	public Quantity(Quantity q)
	{
		value = q.value;
		unit = new HashMap<String,Integer>(q.unit);
	}
	
	/**Constructor that takes in the numerical value of the quantity and
	 * the variables in the numerator and denom
	 * @param val
	 * @param numer
	 * @param denom
	 */
	public Quantity(double val, List<String> numer, List<String> denom)
	{
		if(numer == null || denom == null)
		{
			throw new IllegalArgumentException();
		}
		value = val;
		this.unit = new HashMap<String,Integer>();
		//puts each key from each list into the quantity's hashmap
		for (Object key : numer)
		{
			adjustExponentBy(key.toString(), 1);
		}
		for (Object key2 : denom) 
		{
			adjustExponentBy(key2.toString(), -1);
		}
	}
	
	/**Multiplies the calling object by the quantity q
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @param q
	 * @return
	 * @throws IllegalArgumentException
	 */
	public Quantity mul(Quantity q) throws IllegalArgumentException
	{
		//throws illegalarguement if q is null
		if(q == null)
		{
			throw new IllegalArgumentException();
		}
		Quantity newquant = new Quantity(this);
		double newval = this.value*q.value;
		newquant.value = newval;
		//multiplies each of the variables in q with the calling object and places it in
		//the newquant
		for(String qstrings : q.unit.keySet())
		{
			newquant.adjustExponentBy(qstrings, q.unit.get(qstrings));
		}
		/*int tempval;
		for(String qstrings : q.unit.keySet())
		{
			if(this.unit.containsKey(qstrings))
			{
				tempval = q.unit.get(qstrings) + this.unit.get(qstrings);
				if(tempval == 0)
				{
					newquant.unit.remove(qstrings);
				}
				else
				{
					newquant.adjustExponentBy(qstrings,q.unit.get(qstrings));
				}
			}
			else
			{
				newquant.adjustExponentBy(qstrings, q.unit.get(qstrings));
			}
		}*/
		return newquant;
	}
	
	/**divides the calling object by the quantity q
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @param q
	 * @return newquant
	 * @throws IllegalArgumentException
	 * */
	public Quantity div(Quantity q) throws IllegalArgumentException
	{
		//throws illegalargument if q is null or dividing by zero
		if(q == null || q.value == 0)
		{
			throw new IllegalArgumentException();
		}
		
		Quantity newquant = new Quantity(this);
		double newval = this.value/q.value;
		newquant.value = newval;
		//divide the variables in the calling object by the ones in q
		//and places it newquant
		for(String qstrings : q.unit.keySet())
		{
			newquant.adjustExponentBy(qstrings,-q.unit.get(qstrings));
		}
		/*int tempval;
		for(String qstrings : q.unit.keySet())
		{
			if(this.unit.containsKey(qstrings))
			{
				tempval = q.unit.get(qstrings) - this.unit.get(qstrings);
				if(tempval == 0)
				{
					newquant.unit.remove(qstrings);
				}
				else
				{
					newquant.adjustExponentBy(qstrings,-this.unit.get(qstrings));
				}
			}
		}*/
		return newquant;
	}
	
	/**raises the calling object to the specified power
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @param power
	 * @return
	 * @throws IllegalArgumentException
	 */
	public Quantity pow(int power) throws IllegalArgumentException
	{
		Quantity newquant = new Quantity();
		//if the quantity is raised to 0 then the value is 1.0 which
		//is the same as newquant
		if(power == 0)
		{
			return newquant;
		}
		double newval = Math.pow(this.value,power);
		newquant.value = newval;
		//raises each of the variables in the calling object and
		//adds them to the newquant
		for(String thisstrings : this.unit.keySet())
		{
			newquant.adjustExponentBy(thisstrings,power*this.unit.get(thisstrings));
		}
		/*Set<String> thisstringkeys = this.unit.keySet();
		Object[] thisobjectarray = thisstringkeys.toArray();
		String[] thisstringarray = new String[thisobjectarray.length];
		for(int i = 0; i<thisobjectarray.length;i++)
		{
			thisstringarray[i] = (String) thisobjectarray[i];
		}
		int tempval;
		for(int i = 0; i<thisstringarray.length;i++)
		{
			tempval = this.unit.get(thisstringarray[i])*power;
			newquant.unit.put(thisstringarray[i], tempval);
		}*/
		return newquant;
	}
	
	/**adds the quantity q to the calling object
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @param q
	 * @return newquant
	 * @throws IllegalArgumentException
	 */
	public Quantity add(Quantity q) throws IllegalArgumentException
	{
		Quantity newquant = new Quantity();
		//illegalargument if q is null or the two hashmap sets do not correspond
		if(q == null || !this.unit.entrySet().equals(q.unit.entrySet()))
		{
			throw new IllegalArgumentException();
		}
		double newval = this.value + q.value;
		newquant.value = newval;
		newquant.unit = this.unit;
		return newquant;
	}
	
	/**subtracts the quantity q
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @param q
	 * @return newquant
	 * @throws IllegalArgumentException
	 */
	public Quantity sub(Quantity q) throws IllegalArgumentException
	{
		Quantity newquant = new Quantity();
		//illegalargument if q is null or the two hashmap sets do not correspond
		if(q == null || !this.unit.entrySet().equals(q.unit.entrySet()))
		{
			throw new IllegalArgumentException();
		}
		double newval = this.value - q.value;
		newquant.value = newval;
		newquant.unit = this.unit;
		return newquant;
	}
	
	/**Negates the calling object
	 * and returns it in a new quantity w/o modifying the original quantity
	 * @return newquant
	 */
	public Quantity negate()
	{
		Quantity newquant = new Quantity(this);
		newquant.value = -newquant.value;
		return newquant;
	}
	
	/**checks if two quantities are equal
	 */
	public boolean equals(Object o)
	{
		if(o != null && o instanceof Quantity)
		{
			Quantity oquant = (Quantity)o;
			return oquant.toString().equals(this.toString());
		}
		return false;
	}
	/**
	 * gives the hashcode of a quantity
	 */
	public int hashCode()
	{
		return toString().hashCode();
	}
	
	/**normalizes a unit by using the conversion value obtained
	 * from normalizedUnit
	 * @param db
	 * @return newquant
	 */
	public Quantity normalize(Map<String,Quantity> db)
	{
		Quantity newquant = new Quantity();
		newquant.value = this.value;
		for(String thisstrings : unit.keySet())
		{
			//normquant uses the value from the normalizedUnit method
			//in order to convert to the the normalized version of the
			//calling object. This value is stored in newquant which is returned
			//to normalized unit until it is fully normalized
			Quantity normquant = normalizedUnit(thisstrings,db);
			normquant = normquant.pow(unit.get(thisstrings));
			newquant = newquant.mul(normquant);
		}
		return newquant;
	}
	/**returns the normalized version of the unit so that normalize can use
	 * it to convert between units in the normalize method
	 * @param name
	 * @param db
	 * @return normquant
	 */
	public static Quantity normalizedUnit(String name, Map<String,Quantity> db)
	{
		if(db.containsKey(name))
		{
			Quantity normquant = db.get(name);
			//returns the quantity from the normalize method
			return normquant.normalize(db);
		}
		List<String> emp = new ArrayList<String>();
		Quantity normquant = new Quantity(1.0,Arrays.asList(name),emp);
		return normquant;
	}
	/**
	 * Method that converts quantity to a string representation
	 */
	public String toString()
	{
		// XXX You will need to fix these lines to match your fields! 
		double valueOfTheQuantity = this.value;
		Map<String,Integer> mapOfTheQuantity = this.unit;
		// Ensure we get the units in order 
		TreeSet<String> orderedUnits =  new TreeSet<String>(mapOfTheQuantity.keySet());
		StringBuffer unitsString = new StringBuffer();
		for (String key : orderedUnits) {
			int expt = mapOfTheQuantity.get(key);
			unitsString.append(" " + key);
			if (expt != 1)
				unitsString.append("^" + expt);
		}
		// Used to convert doubles to a string with a  
		// fixed maximum number of decimal places.
		DecimalFormat df = new DecimalFormat("0.0####");
		// Put it all together and return.
		return df.format(valueOfTheQuantity) + unitsString.toString();
	}
	/**
	 * helper method to change the exponents of the variables in a quantity
	 * @param unitName
	 * @param delta
	 */
	private void adjustExponentBy(String unitName,int delta)
	{
		//If delta is 0 then it does nothing
		if(delta == 0)
		{
			return;
		}
		//If the string is in the callingobject's hashmap
		//and the changed value of the exponent is not zero
		//the exponent value will be adjusted by delta.
		//if the changed value is zero then the variable is removed
		if(unit.containsKey(unitName))
		{
			int tempvalue = unit.get(unitName) + delta;
			if(tempvalue == 0)
			{
				unit.remove(unitName);
			}
			else
			{
				unit.put(unitName, tempvalue);
			}
		}
		//if the variable is not found in the quantity then it will
		//be placed there with the exponent value of delta
		else
		{
			unit.put(unitName,delta);
		}
	}
}