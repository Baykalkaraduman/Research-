#include <iostream>
#include <iomanip>

using namespace std;

/*
==========================================================
            Package Shipping Cost Calculator
==========================================================

This program calculates the shipping cost of a package.

Rules

• Maximum dimension: 15 cm
• Base cost: $2.50

Volume <= 1000 cm³
    → Base cost

1000 < Volume <= 2000 cm³
    → 10% surcharge

Volume > 2000 cm³
    → 25% surcharge

If any dimension exceeds 15 cm,
the package is rejected.
*/

int main() {

    /*
    ------------------------------------------------------
                    Constants
    ------------------------------------------------------
    */

    const double BASE_COST {2.50};

    const int MAX_DIMENSION {15};

    const int TIER1_VOLUME {1000};
    const int TIER2_VOLUME {2000};

    const double TIER1_SURCHARGE {0.10};
    const double TIER2_SURCHARGE {0.25};

    /*
    ------------------------------------------------------
                    Variables
    ------------------------------------------------------
    */

    int length {};
    int width {};
    int height {};

    double shipping_cost {BASE_COST};

    /*
    ------------------------------------------------------
                    User Input
    ------------------------------------------------------
    */

    cout << "=========================================\n";
    cout << "      Package Shipping Calculator\n";
    cout << "=========================================\n\n";

    cout << "Enter package length (cm): ";
    cin >> length;

    cout << "Enter package width (cm): ";
    cin >> width;

    cout << "Enter package height (cm): ";
    cin >> height;

    /*
    ------------------------------------------------------
                Dimension Validation
    ------------------------------------------------------
    */

    if (length > MAX_DIMENSION ||
        width  > MAX_DIMENSION ||
        height > MAX_DIMENSION) {

        cout << "\nPackage rejected!" << endl;
        cout << "Maximum allowed dimension is "
             << MAX_DIMENSION << " cm." << endl;

        return 0;
    }

    /*
    ------------------------------------------------------
                Volume Calculation
    ------------------------------------------------------
    */

    int volume {length * width * height};

    cout << "\nPackage volume : "
         << volume
         << " cm^3"
         << endl;

    /*
    ------------------------------------------------------
                Shipping Cost Calculation
    ------------------------------------------------------
    */

    if (volume > TIER2_VOLUME) {

        shipping_cost += shipping_cost * TIER2_SURCHARGE;

    }
    else if (volume > TIER1_VOLUME) {

        shipping_cost += shipping_cost * TIER1_SURCHARGE;

    }

    /*
    ------------------------------------------------------
                Output Formatting
    ------------------------------------------------------
    */

    cout << fixed << setprecision(2);

    cout << "\nShipping Cost : $"
         << shipping_cost
         << endl;

    /*
    ------------------------------------------------------
                    Added Example
    ------------------------------------------------------
    */

    // Added:
    // Show the surcharge applied.

    if (volume > TIER2_VOLUME)

        cout << "Applied surcharge : 25%\n";

    else if (volume > TIER1_VOLUME)

        cout << "Applied surcharge : 10%\n";

    else

        cout << "Applied surcharge : None\n";

    return 0;
}