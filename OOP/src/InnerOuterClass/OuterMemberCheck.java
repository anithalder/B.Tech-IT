import java.util.Scanner;

public class OuterMemberCheck {
    private Object member; // Can be int or String

    public OuterMemberCheck(Object member) {
        this.member = member;
    }

    public Object getMember() {
        return member;
    }

    public void setMember(Object member) {
        this.member = member;
    }

    // Nested class to check the type of outer class member
    public class MemberChecker {
        public String checkMemberType() {
            if (member instanceof Integer) {
                return "The member is of type Integer.";
            } else if (member instanceof String) {
                return "The member is of type String.";
            } else {
                return "The member is of an unknown type.";
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a value: ");
        String input = sc.nextLine();

        Object member = null;

        try {
            member = Integer.parseInt(input);
        } catch (Exception e) {
            // If parsing fails, treat it as a String
            member = input.isEmpty() ? null : input;
        }

        OuterMemberCheck outer = new OuterMemberCheck(member);
        OuterMemberCheck.MemberChecker checker = outer.new MemberChecker();
        System.out.println(checker.checkMemberType());

        sc.close();
    }
}