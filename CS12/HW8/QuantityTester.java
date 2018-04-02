import junit.framework.* ;
import java.util.*;
/*Name: Andrew Hwang
ID: A11570188
LOGIN: cs12sda
Date: 6/4/14*/
public class QuantityTester extends TestCase {

	private Quantity q;
	private Quantity asdf;
	private List<String> emp;
	private Map<String,Quantity> db;
	public QuantityTester()
	{
		super();
	}
	
	/** The setUp creates a no arg quantity, empty list and gets the
	 * Quantity database
	 */
	public void setUp()
	{
		q = new Quantity();
		emp = new ArrayList<String>();
		db = QuantityDB.getDB();
	}
	
	/**Tests the default constructor
	 * 
	 */
	public void testDefaultConstructor()
	{
		assertEquals("1.0",q.toString());
	}
	/**Tests the copy constructor*/
	public void testCopyConstructor()
	{
		q = new Quantity();
		Quantity r = new Quantity(q);
		assertEquals(q,r);
	}
	/**Tests the 3 arg constructor*/
	public void test3ArgConstructor()
	{
		asdf = new Quantity(9.8,Arrays.asList("m"),Arrays.asList("s","s"));
		assertEquals("9.8 m s^-2",asdf.toString());
	}
	/**Tests the multiply method*/
	public void testMul()
	{
		Quantity mq = new Quantity(2,Arrays.asList("m"),emp);
		Quantity mulquant = q.mul(mq);
		assertEquals("2.0 m",mulquant.toString());
	}
	/**Tests the divide method*/
	public void testDiv()
	{
		Quantity dq = new Quantity(2,emp,Arrays.asList("m"));
		Quantity divquant = q.div(dq);
		assertEquals("0.5 m",divquant.toString());
	}
	/**Tests the power method*/
	public void testPow()
	{
		Quantity pq = new Quantity(10,Arrays.asList("s"),emp);
		Quantity powquant = pq.pow(2);
		assertEquals("100.0 s^2",powquant.toString());
	}
	/**Tests the add method*/
	public void testAdd()
	{
		Quantity aq = new Quantity(4,emp,emp);
		Quantity addquant = aq.add(q);
		assertEquals("5.0",addquant.toString());
	}
	/**Tests the subract method*/
	public void testSub()
	{
		Quantity sq = new Quantity(4,Arrays.asList("m"),emp);
		Quantity sq2 = new Quantity(2,Arrays.asList("m"),emp);
		Quantity subquant = sq.sub(sq2);
		assertEquals("2.0 m",subquant.toString());
	}
	/**Tests the negate method*/
	public void testNegate()
	{
		Quantity negquant = q.negate();
		assertEquals("-1.0",negquant.toString());
	}
	/**Tests the equals method*/
	public void testEquals()
	{
		Object eo = new Quantity(1.11111,emp,emp);
		Quantity equalsquant = new Quantity(1.11111,emp,emp);
		assertTrue(equalsquant.equals(eo));
		Object eo1 = new Quantity(1.11115,emp,emp);
		assertFalse(equalsquant.equals(eo1));
	}
	/**Tests the hashcode method*/
	public void testHashCode()
	{
		Quantity hashquant = new Quantity();
		assertEquals(q.toString().hashCode(),hashquant.toString().hashCode());
	}
	/**Tests the normalize method*/
	public void testNormalize()
	{
		Quantity nq = new Quantity(2,Arrays.asList("hour"),emp);
		assertEquals("7200.0 second",nq.normalize(db).toString());
	}
	/**Tests the normalizedUnit method*/
	public void testNormalizedUnit()
	{
		assertEquals("3600.0 second",Quantity.normalizedUnit("hour",db).toString());
	}
	/**Checks if units are properly removed, for example
	 * m/m should be removed and not equal m^0
	 */
	public void testCanceling()
	{
		Quantity a = new Quantity(10,Arrays.asList("m"),emp);
		Quantity b = new Quantity(2,emp,Arrays.asList("m"));
		Quantity ab = a.mul(b);
		assertEquals("20.0",ab.toString());
	}
}