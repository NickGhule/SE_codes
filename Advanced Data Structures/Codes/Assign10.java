package p1;
class pk1{


class AdditionPrivate
{
    private int num_1 = 10,num_2 = 20;
    public int getnum_1()
    {
        return num_1;
    }
    public int getnum_2()
    {
        return num_2;
    }
}

class AdditionPublic
{
    public int num_1 = 20,num_2 = 20;
}

class AdditionProtected
{
    protected int num_1 = 30,num_2 = 20;
    protected int getnum_1()
    {
        return num_1;
    }
    protected int getnum_2()
    {
        return num_2;
    }
}

class AdditionProtectedTemp extends AdditionProtected
{
    //NO data added Everthing inherited from Base class
}

class assign10
{
    public static void main(final String[] args)
    {
        AdditionPrivate private_Object = new AdditionPrivate();
        int sum = private_Object.getnum_1() + private_Object.getnum_2();
        System.out.print("Addition Using Private members ::\t");
        System.out.println(sum);                                        // sum should be 30 

        AdditionPublic public_Object = new AdditionPublic();
        sum = public_Object.num_1 + public_Object.num_2;
        System.out.print("Addition Using Public members ::\t");
        System.out.println(sum);                                        // sum should be 40

        AdditionProtected protected_Object = new AdditionProtected();       
        sum = protected_Object.getnum_1() + protected_Object.getnum_2();
        System.out.print("Addition Using Protected members ::\t");
        System.out.println(sum);                                        // sum should be 50 
    }
}
}