#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_only_digits(const string &src_string)
{
    bool result = true;
    auto iterator = src_string.begin();

    while (iterator != src_string.end())
    {
        if (!isdigit(*iterator))
        {
            result = false;
            break;
        }
        iterator++;
    }

    return result;
}

bool is_only_letters(const string& src_string)
{
    bool result = true;
    auto iterator = src_string.begin();

    while (iterator != src_string.end())
    {
        if (!isalpha(*iterator))
        {
            result = false;
            break;
        }
        iterator++;
    }

    return result;
}

class Retention
{
private:
    string period;
    string type;
    double sum;
public:
    Retention()
    {
        period = "N/A";
        type = "N/A";
        sum = 0.0;
    }

    Retention(const string _period, const string _type, const double _sum)
    {
        if (_period.length() == 8 && is_only_digits(_period))
        {
            period = _period;
        }
        else
        {
            period = "N/A";
        }

        if (_type.length() == 3 && is_only_digits(_type))
        {
            type = _type;
        }
        else
        {
            type = "N/A";
        }

        if (_sum >= 0.0)
        {
            sum = _sum;
        }
        else
        {
            sum = 0.0;
        }
    }

    Retention(const Retention& src_object)
    {
        period = src_object.period;
        type = src_object.type;
        sum = src_object.sum;
    }

    ~Retention() { }

    string get_period() const { return period; }
    string get_type() const { return type; }
    double get_sum() const { return sum; }

    bool set_period(const string settable_period)
    {
        bool result = false;

        if (settable_period.length() == 8 && is_only_digits(settable_period))
        {
            period = settable_period;
            result = true;
        }

        return result;
    }

    bool set_type(const string settable_type)
    {
        bool result = false;

        if (settable_type.length() == 3 && is_only_digits(settable_type))
        {
            type = settable_type;
            result = true;
        }

        return result;
    }

    double set_sum(const double settable_sum)
    {
        bool result = false;

        if (settable_sum > 0.0)
        {
            sum = settable_sum;
            result = true;
        }

        return result;
    }
};

class Accural : public Retention
{
private:
    unsigned long int attendance;
    unsigned long int hours;
public:
    Accural() : Retention()
    {
        attendance = 0;
        hours = 0;
    }

    Accural(const string _period, const  string _type, const  double _sum, const  unsigned long int _attendance, const  unsigned long int _hours) : Retention(_period, _type, _sum)
    {
        if (_attendance > 0) attendance = _attendance;
        if (_hours > 0) hours = _hours;
    }

    Accural(const Accural& src_object) : Retention(src_object)
    {
        attendance = src_object.attendance;
        hours = src_object.hours;
    }

    ~Accural() { }

    unsigned long int get_attendance() const { return attendance; }
    unsigned long int get_hours() const { return hours; }

    bool set_attendance(const unsigned long int settable_attendance)
    {
        bool result = false;

        if (settable_attendance > 0)
        {
            attendance = settable_attendance;
            result = true;
        }

        return result;
    }

    bool set_hours(const unsigned long int settable_hours)
    {
        bool result = false;

        if (settable_hours > 0)
        {
            hours = settable_hours;
            result = true;
        }

        return result;
    }
};

class Employee
{
private:
    string service_number;
    string full_name;
    string id_code;
    string section_code;
    string profession_code;
    string period;
    double salary;
    unsigned long int attendance_in_schedule;
    unsigned long int accurals_amount;
	Accural** accurals;
    unsigned long int retentions_amount;
    Retention** retentions;
public:
    Employee()
    {
        service_number = "N/A";
        full_name = "N/A";
        id_code = "N/A";
        profession_code = "N/A";
        period = "N/A";
        salary = 0.0;
        accurals_amount = 0;
        accurals = nullptr;
        retentions_amount = 0;
        retentions = nullptr;
    }

    Employee(const string _service_number, const  string _full_name, const  string _id_code, const  string _section_code, const  string _profession_code, const  string _period, const  double _salary, const  unsigned long int _attendance_in_schedule, const  unsigned long int _accurals_amount, const  unsigned long int _retentions_amount)
    {
        if (_service_number.length() > 0 && is_only_digits(_service_number))
        {
            service_number = _service_number;
        }
        else
        {
            service_number = "N/A";
        }

        if (_full_name.length() > 0 && is_only_letters(_full_name))
        {
            full_name = _full_name;
        }
        else
        {
            full_name = "N/A";
        }

        if (_id_code.length() > 0 && is_only_digits(_id_code))
        {
            id_code = _id_code;
        }
        else
        {
            id_code = "N/A";
        }

        if (_section_code.length() > 0)
        {
            section_code = _section_code;
        }
        else
        {
            section_code = "N/A";
        }

        if (_profession_code.length() > 0 && is_only_digits(_profession_code))
        {
            profession_code = _profession_code;
        }
        else
        {
            profession_code = "N/A";
        }

        if (_period.length() == 8 && is_only_digits(_period))
        {
            period = _period;
        }
        else
        {
            period = "N/A";
        }

        if (_salary >= 0.0)
        {
            salary = _salary;
        }
        else
        {
            salary = 0.0;
        }

        if (_attendance_in_schedule >= 0)
        {
            attendance_in_schedule = _attendance_in_schedule;
        }
        else
        {
            attendance_in_schedule = 0;
        }

        if (_accurals_amount > 0)
        {
            accurals_amount = _accurals_amount;
            accurals = new Accural * [accurals_amount];
            for (int i = 0; i < accurals_amount; i++)
            {
                accurals[i] = new Accural();
            }
        }
        else
        {
            accurals_amount = 0;
            accurals = nullptr;
        }

        if (_retentions_amount > 0)
        {
            retentions_amount = _retentions_amount;
            retentions = new Retention * [retentions_amount];
            for (int i = 0; i < retentions_amount; i++)
            {
                retentions[i] = new Retention();
            }
        }
        else
        {
            retentions_amount = 0;
            retentions = nullptr;
        }
    }

    Employee(const Employee& src_object)
    {
        service_number = src_object.service_number;
        full_name = src_object.full_name;
        id_code = src_object.id_code;
        profession_code = src_object.profession_code;
        period = src_object.period;
        salary = src_object.salary;
        accurals_amount = src_object.accurals_amount;
        if (accurals_amount > 0)
        {
            accurals = new Accural * [accurals_amount];
            for (int i = 0; i < accurals_amount; i++)
            {
                accurals[i] = new Accural(*(src_object.accurals[i]));
            }
        }
        else
        {
            accurals = nullptr;
        }
        retentions_amount = src_object.retentions_amount;
        if (retentions_amount > 0)
        {
            retentions = new Retention * [retentions_amount];
            for (int i = 0; i < retentions_amount; i++)
            {
                retentions[i] = new Retention(*(src_object.retentions[i]));
            }
        }
        else
        {
            retentions = nullptr;
        }
    }

    ~Employee()
    {
        if (accurals_amount > 0 && accurals != nullptr)
        {
            for (int i = 0; i < accurals_amount; i++)
            {
                delete accurals[i];
            }
            delete[]accurals;
        }
        if (retentions_amount > 0 && retentions != nullptr)
        {
            for (int i = 0; i < retentions_amount; i++)
            {
                delete retentions[i];
            }
            delete[]retentions;
        }
    }

    string get_service_number() const { return service_number; }
    string get_full_name() const { return full_name; }
    string get_id_code() const { return id_code; }
    string get_profession_code() const { return profession_code; }
    string get_period() const { return period; }
    double get_salary() const { return salary; }
    unsigned long int get_attendance_in_schedule() const { return attendance_in_schedule; }
    unsigned long int get_accurals_amount() const { return accurals_amount; }
    unsigned long int get_retentions_amount() const { return retentions_amount; }

    bool set_service_number(const string settable_service_number)
    {
        bool result = false;

        if (settable_service_number.length() > 0 && is_only_digits(settable_service_number))
        {
            service_number = settable_service_number;
            result = true;
        }

        return result;
    }

    bool set_full_name(const string settable_full_name)
    {
        bool result = false;

        if (settable_full_name.length() > 0 && is_only_letters(settable_full_name))
        {
            full_name = settable_full_name;
            result = true;
        }

        return result;
    }

    bool set_id_code(const string settable_id_code)
    {
        bool result = false;

        if (settable_id_code.length() > 0 && is_only_digits(settable_id_code))
        {
            id_code = settable_id_code;
            result = true;
        }

        return result;
    }

    bool set_section_code(const string settable_section_code)
    {
        bool result = false;

        if (settable_section_code.length() > 0)
        {
            section_code = settable_section_code;
            result = true;
        }

        return result;
    }

    bool set_professional_code(const string settable_professional_code)
    {
        bool result = false;

        if (settable_professional_code.length() > 0 && is_only_digits(settable_professional_code))
        {
            profession_code = settable_professional_code;
            result = true;
        }

        return result;
    }

    bool set_period(const string settable_period)
    {
        bool result = false;

        if (settable_period.length() == 8 && is_only_digits(settable_period))
        {
            period = settable_period;
            result = true;
        }

        return result;
    }

    bool set_salary(const double settable_salary)
    {
        bool result = false;

        if (settable_salary >= 0.0)
        {
            salary = settable_salary;
            result = true;
        }

        return result;
    }

    bool set_attendance_in_schedule(const unsigned long int settable_attendance_in_schedule)
    {
        bool result = false;

        if (settable_attendance_in_schedule >= 0)
        {
            attendance_in_schedule = settable_attendance_in_schedule;
            result = true;
        }

        return result;
    }
};

class Section
{
private:
    string section_code;
    unsigned long int employees_amount;
    Employee** employees;
public:
    Section()
    {
        section_code = "N/A";
        employees_amount = 0;
        employees = nullptr;
    }

    Section(const string _section_code, const unsigned long int _employees_amount)
    {
        if (_section_code.length() > 0) section_code = _section_code;
        if (_employees_amount > 0)
        {
            employees_amount = _employees_amount;
            employees = new Employee * [employees_amount];
            for (int i = 0; i < employees_amount; i++)
            {
                employees[i] = new Employee();
            }
        }
        else
        {
            employees_amount = 0;
            employees = nullptr;
        }
    }

    Section(const Section& src_object)
    {
        section_code = src_object.section_code;
        employees_amount = src_object.employees_amount;
        if (employees_amount > 0)
        {
            employees = new Employee * [employees_amount];
            for (int i = 0; i < employees_amount; i++)
            {
                employees[i] = new Employee(*(src_object.employees[i]));
            }
        }
        else
        {
            employees = nullptr;
        }
    }

    ~Section()
    {
        if (employees_amount > 0 && employees != nullptr)
        {
            for (int i = 0; i < employees_amount; i++)
            {
                delete employees[i];
            }
            delete[]employees;
        }
    }

    string get_section_code() const { return section_code; }
    unsigned long int get_employees_amount() const { return employees_amount; }

    bool set_section_code(const string settable_section_code)
    {
        bool result = false;

        if (settable_section_code.length() > 0)
        {
            section_code = settable_section_code;
            result = true;
        }

        return result;
    }
};

class List
{
private:
    string list_name;
    unsigned long int sections_amount;
    Section** sections;
public:
    List()
    {
        list_name = "N/A";
        sections_amount = 0;
        sections = nullptr;
    }

    List(const string _list_name, const unsigned long int _sections_amount)
    {
        if (_list_name.length() > 0) list_name = _list_name;
        if (_sections_amount > 0)
        {
            sections_amount = _sections_amount;
            sections = new Section * [sections_amount];
            for (int i = 0; i < sections_amount; i++)
            {
                sections[i] = new Section();
            }
        }
        else
        {
            sections_amount = 0;
            sections = nullptr;
        }
    }

    List(const List& src_object)
    {
        list_name = src_object.list_name;
        sections_amount = src_object.sections_amount;
        if (sections_amount > 0)
        {
            sections = new Section * [sections_amount];
            for (int i = 0; i < sections_amount; i++)
            {
                sections[i] = new Section(*(src_object.sections[i]));
            }
        }
        else
        {
            sections = nullptr;
        }
    }

    ~List()
    {
        if (sections_amount > 0 && sections != nullptr)
        {
            for (int i = 0; i < sections_amount; i++)
            {
                delete sections[i];
            }
            delete[]sections;
        }
    }

    string get_list_name() const { return list_name; }
    unsigned long int get_sections_amount() const { return sections_amount; }

    bool set_list_name(const string settable_list_name)
    {
        bool result = false;

        if (settable_list_name.length() > 0)
        {
            list_name = settable_list_name;
            result = true;
        }

        return result;
    }
};

int main()
{
    cout << "Hello World!\n";
}
