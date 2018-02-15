/*
Jerry Wan
Rec 8
*/

#include "Student.h"
#include "Course.h"
#include "Registrar.h"
#include <iostream>

using namespace std;
using namespace Bklyn_Poly;

int main()
{
    Registrar registrar;

    cout << "No courses or students added yet\n";
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "add_course CS101.001\n";
    registrar.add_course("CS101.001");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "add_student FritzTheCat\n";
    registrar.add_student("FritzTheCat");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "add_course CS102.001\n";
    registrar.add_course("CS102.001");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "enroll_in_course FritzTheCat CS102.001\n";
    registrar.enroll_in_course("FritzTheCat", "CS102.001");
    cout << "enroll_in_course FritzTheCat CS101.001\n";
    registrar.enroll_in_course("FritzTheCat", "CS101.001");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "enroll_in_course Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
    registrar.enroll_in_course("Bullwinkle", "CS101.001");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    cout << "cancel_course CS102.001\n";
    registrar.cancel_course("CS102.001");
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();

    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;  // or registrar.printReport()
    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;  // or registrar.printReport()
    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;  // or registrar.printReport()
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    //cout << registrar << endl;  // or registrar.printReport()
    registrar.print_report();
}

/* OUTPUT
No courses or students added yet
=== NYU REGISTRAR PRINT ===
======= END REPORT ========
add_course CS101.001
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
======= END REPORT ========
add_student FritzTheCat
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
======= END REPORT ========
add_course CS102.001
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
Course name: CS102.001
Students in course:
======= END REPORT ========
enroll_in_course FritzTheCat CS102.001
enroll_in_course FritzTheCat CS101.001
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
FritzTheCat
Course name: CS102.001
Students in course:
FritzTheCat
======= END REPORT ========
enroll_in_course Bullwinkle CS101.001
Should fail, i.e. do nothing, since Bullwinkle is not a student.
Error.
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
FritzTheCat
Course name: CS102.001
Students in course:
FritzTheCat
======= END REPORT ========
cancel_course CS102.001
=== NYU REGISTRAR PRINT ===
Course name: CS101.001
Students in course:
FritzTheCat
======= END REPORT ========
Purge for start of next semester
=== NYU REGISTRAR PRINT ===
======= END REPORT ========
Press any key to continue . . .
*/
