


class Student {
    private int age;
    public void setAge(int a) {
    if (a > 0) age = a;
    }
    public int getAge() {
    return age;
    }
    public static void main(String[] args) {
    Student s = new Student();
    //Encapsulated access
    s.setAge(20);
    // Output: 20
    System.out.println(s.getAge());
    }
   }