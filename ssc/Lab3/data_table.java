import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class operator {
    String instruction;
    String statement_class;
    int machine_code;

    public void operator_value(String instruction, String statement_class, int machine_code) {
        this.instruction = instruction;
        this.statement_class = statement_class;
        this.machine_code = machine_code;
    }
}

class register {
    String reg_name;
    int machine_code;

    public void register_value(String reg_name, int machine_code) {
        this.reg_name = reg_name;
        this.machine_code = machine_code;
    }
}

class condition_code {
    String condition;
    int machine_code;

    public void condition_code_value(String condition, int machine_code) {
        this.condition = condition;
        this.machine_code = machine_code;
    }
}

class symboltable {
    int symbol_no;
    String symbol_name;
    int address;

}

class literal {
    int literal_no;
    String literal_name;
    int address;

}

class pool_tab {

}

public class data_table {
    public static void main(String[] args) {
        try {
            File file = new File("C:\\Users\\rohit\\Documents\\GitHub\\sem_7\\ssc\\Lab1\\OPTAB.txt");
            Scanner sc = new Scanner(file);
            operator[] OPTAB = new operator[18];
            String S = "";
            while (sc.hasNextLine()) {
                String temp = sc.nextLine();
                S += temp + ' ';
            }
            String[] data = S.split(" ");

            for (int j = 0; j < data.length; j += 3) {
                OPTAB[j / 3] = new operator();
                OPTAB[j / 3].operator_value(data[j], data[j + 1], Integer.parseInt(data[j + 2]));
                // System.out.println(data[j] + " " + data[j + 1] + " " +
                // Integer.parseInt(data[j + 2]));
            }

            /*
             * for (int j = 0; j < data.length; j += 3) {
             * System.out.print(OPTAB[j / 3].instruction + " " + OPTAB[j /
             * 3].statement_class + " "
             * + OPTAB[j / 3].machine_code);
             * }
             */

            // code for register table
            file = new File("C:\\Users\\rohit\\Documents\\GitHub\\sem_7\\ssc\\Lab1\\Register_Table.txt");
            Scanner sc1 = new Scanner(file);
            register[] RTtable = new register[4];
            S = "";
            while (sc1.hasNextLine()) {
                String temp = sc1.nextLine();
                S += temp + ' ';
            }
            data = S.split(" ");

            for (int j = 0; j < data.length; j += 2) {
                RTtable[j / 2] = new register();
                RTtable[j / 2].register_value(data[j], Integer.parseInt(data[j + 1]));
            }

            /*
             * for (int j = 0; j < data.length; j += 2) {
             * System.out.print(RTtable[j / 2].reg_name + " "
             * + RTtable[j / 2].machine_code);
             * }
             */

            // code for condition code
            file = new File("C:\\Users\\rohit\\Documents\\GitHub\\sem_7\\ssc\\Lab1\\Condition_Code.txt");
            Scanner sc2 = new Scanner(file);
            condition_code[] CCtable = new condition_code[6];
            S = "";
            while (sc2.hasNextLine()) {
                String temp = sc2.nextLine();
                S += temp + ' ';
            }
            data = S.split(" ");

            for (int j = 0; j < data.length; j += 2) {
                CCtable[j / 2] = new condition_code();
                CCtable[j / 2].condition_code_value(data[j], Integer.parseInt(data[j + 1]));
            }

            /*
             * for (int j = 0; j < data.length; j += 2) {
             * System.out.print(CCtable[j / 2].reg_name + " "
             * + CCtable[j / 2].machine_code);
             * }
             */
            sc.close();
            sc1.close();
            sc2.close();
            // creating hashmap of all tables
            /* Operator Table */
            HashMap<String, operator> OPTAB_data = new HashMap<>();
            for (int i = 0; i < OPTAB.length; i++) {
                OPTAB_data.put(OPTAB[i].instruction, OPTAB[i]);
            }
            /* Register Table */
            HashMap<String, register> RTtable_data = new HashMap<>();
            for (int i = 0; i < RTtable.length; i++) {
                RTtable_data.put(RTtable[i].reg_name, RTtable[i]);
            }
            /* Condition Code Table */
            HashMap<String, condition_code> CCtable_data = new HashMap<>();
            for (int i = 0; i < CCtable.length; i++) {
                CCtable_data.put(CCtable[i].condition, CCtable[i]);
            }
            /* Symbol Table data to store*/
            ArrayList<String> indexed = new ArrayList<>();
            /* Literal Table data */
            ArrayList<String> literal = new ArrayList<>();
            String input_data = reader.read();
            int Location_Counter = 0;
            // System.out.println(input_data);
            String[] output = string_token.token(input_data, "\n");
            for (int i = 0; i < output.length; i++) {
                String[] temp = string_token.token(output[i], " ");
                if (temp[0].equals("START"))
                {
                    try{
                        Location_Counter = Integer.parseInt(temp[1]);
                    }
                    catch(Exception e)
                    {
                        Location_Counter = 0;
                    }
                }
                // System.out.println(temp.length);
                if (temp[0] != "END" && temp.length == 1) {
                    // System.out.print(temp.toString());
                    temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ',' + OPTAB_data.get(temp[0]).machine_code
                            + ')';
                    output[i] = Location_Counter + "  "  + temp[0];

                } else if (temp.length == 2) {
                    if (temp[0].equals("LAST")) {
                        try {
                            Integer.parseInt(temp[0]);
                            temp[0] = "(C," + temp[0] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[0] = "(S," + index_in_symboltable(indexed, temp[0]) + ")";
                        }
                        temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ','
                                + OPTAB_data.get(temp[1]).machine_code
                                + ')';
                        output[i] = Location_Counter + "  "  + temp[1];
                    } else {
                        temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ','
                                + OPTAB_data.get(temp[0]).machine_code
                                + ')';
                        try {
                            Integer.parseInt(temp[1]);
                            temp[1] = "(C," + temp[1] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[1] = "(S," + index_in_symboltable(indexed, temp[1]) + ")";
                        }
                        output[i] = Location_Counter + "  "  + temp[0] + temp[1];
                    }
                } else if (temp.length == 3) {
                    try{
                        Location_Counter += Integer.parseInt(temp[2]);
                    }
                    catch(Exception e)
                    {
                        Location_Counter++;
                    }
                    if (temp[0].equals("BACK")) {
                        try {
                            Integer.parseInt(temp[0]);
                            temp[0] = "(C," + temp[0] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[0] = "(S," + index_in_symboltable(indexed, temp[0]) + ")";
                        }
                        temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ','
                                + OPTAB_data.get(temp[1]).machine_code
                                + ')';
                        try {
                            Integer.parseInt(temp[2]);
                            temp[2] = "(C," + temp[2] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                        }
                        output[i] = Location_Counter + "  " + temp[1] + temp[2];
                    } else if (temp[0].length() > 1 && indexed.contains(temp[0])) {
                        temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ',' +
                                OPTAB_data.get(temp[1]).machine_code
                                + ')';
                        // System.out.print(temp[1] + "-");
                        try {
                            Integer.parseInt(temp[2]);
                            temp[2] = "(C," + temp[2] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                        }
                        output[i] = Location_Counter + "  "+  temp[1] + temp[2];
                    } else if (temp[0].length() > 1) {
                        temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ',' +
                                OPTAB_data.get(temp[0]).machine_code
                                + ')';
                        // System.out.print(temp[1] + "-");
                        try {
                            temp[1] = " " + RTtable_data.get(temp[1]).machine_code + " ";
                        } catch (Exception e) {
                            temp[1] = " " + CCtable_data.get(temp[1]).machine_code + " ";
                        }
                        try {
                            Integer.parseInt(temp[2]);
                            temp[2] = "(C," + temp[2] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                        }
                        output[i] =Location_Counter + "  " +  temp[0] + temp[1] + temp[2];
                    } else if (temp[0].length() == 1) {
                        try {
                            Integer.parseInt(temp[0]);
                            temp[0] = "(C," + temp[0] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[0] = "(S," + index_in_symboltable(indexed, temp[0]) + ")";
                        }
                        temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ',' +
                                OPTAB_data.get(temp[1]).machine_code
                                + ')';
                        // System.out.print(temp[1] + "-");
                        try {
                            Integer.parseInt(temp[2]);
                            temp[2] = "(C," + temp[2] + ")";
                        } catch (NumberFormatException e) {
                            // Error;
                            temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                        }

                        output[i] = Location_Counter + "  "+  temp[1] + temp[2];
                    }

                } else if (temp.length == 4) {
                    // if(temp)
                    temp[0] = "(S," + index_in_symboltable(indexed, temp[0]) + ")";

                    temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ',' + OPTAB_data.get(temp[1]).machine_code
                            + ')';
                    temp[2] = " " + RTtable_data.get(temp[2]).machine_code + " ";
                    try {
                        Integer.parseInt(temp[3]);
                        temp[3] = "(C," + temp[3] + ")";
                    } catch (NumberFormatException e) {
                        // Error;
                        temp[3] = "(S," + index_in_symboltable(indexed, temp[3]) + ")";
                    }
                    output[i] = Location_Counter + "  "  + temp[1] + temp[2] + temp[3];
                }
                System.out.println(output[i]);
            }
            /* Printing the pass-1 */
            System.out.println("Ouput After Pass1: ");
            for (int i = 0; i < output.length; i++) {
                System.out.println(output[i]);
            }
            System.out.println("Symbol Table: ");
            for (int i = 0; i < indexed.size(); i++) {
                System.out.println(indexed.get(i));
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static int index_in_symboltable(ArrayList<String> indexed, String S) {
        int index = 0;
        for (String str : indexed) {
            if (str.equals(S)) {
                return index + 1;
                // If the string is found, return true
            }
            index++;
        }
        indexed.add(S);
        return indexed.indexOf(S) + 1;
    }

    public static int index_in_literaltable(ArrayList<String> literal, String S) {
        int index = 0;
        for (String str : literal) {
            if (str.equals(S)) {
                return index + 1;
                // If the string is found, return true
            }
            index++;
        }
        literal.add(S);
        return literal.indexOf(S) + 1;
    }
}
