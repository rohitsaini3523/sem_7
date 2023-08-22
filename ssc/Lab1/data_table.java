import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class optable {
    String instruction;
    String statement_class;
    int machine_code;

    public void optable_value(String instruction, String statement_class, int machine_code) {
        this.instruction = instruction;
        this.statement_class = statement_class;
        this.machine_code = machine_code;
    }
}

class rttable {
    String reg_name;
    int machine_code;

    public void rttable_value(String reg_name, int machine_code) {
        this.reg_name = reg_name;
        this.machine_code = machine_code;
    }
}

class cctable {
    String condition;
    int machine_code;

    public void cctable_value(String condition, int machine_code) {
        this.condition = condition;
        this.machine_code = machine_code;
    }
}

public class data_table {
    public static void main(String[] args) {
        try {
            File file = new File("C:\\Users\\rohit\\Documents\\GitHub\\sem_7\\ssc\\Lab1\\OPTAB.txt");
            Scanner sc = new Scanner(file);
            optable[] OPTAB = new optable[18];
            String S = "";
            while (sc.hasNextLine()) {
                String temp = sc.nextLine();
                S += temp + ' ';
            }
            String[] data = S.split(" ");

            for (int j = 0; j < data.length; j += 3) {
                OPTAB[j / 3] = new optable();
                OPTAB[j / 3].optable_value(data[j], data[j + 1], Integer.parseInt(data[j + 2]));
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
            rttable[] RTtable = new rttable[4];
            S = "";
            while (sc1.hasNextLine()) {
                String temp = sc1.nextLine();
                S += temp + ' ';
            }
            data = S.split(" ");

            for (int j = 0; j < data.length; j += 2) {
                RTtable[j / 2] = new rttable();
                RTtable[j / 2].rttable_value(data[j], Integer.parseInt(data[j + 1]));
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
            cctable[] CCtable = new cctable[6];
            S = "";
            while (sc2.hasNextLine()) {
                String temp = sc2.nextLine();
                S += temp + ' ';
            }
            data = S.split(" ");

            for (int j = 0; j < data.length; j += 2) {
                CCtable[j / 2] = new cctable();
                CCtable[j / 2].cctable_value(data[j], Integer.parseInt(data[j + 1]));
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
            HashMap<String, optable> OPTAB_data = new HashMap<>();
            for (int i = 0; i < OPTAB.length; i++) {
                OPTAB_data.put(OPTAB[i].instruction, OPTAB[i]);
            }

            HashMap<String, rttable> RTtable_data = new HashMap<>();
            for (int i = 0; i < RTtable.length; i++) {
                RTtable_data.put(RTtable[i].reg_name, RTtable[i]);
            }
            HashMap<String, cctable> CCtable_data = new HashMap<>();
            for (int i = 0; i < CCtable.length; i++) {
                CCtable_data.put(CCtable[i].condition, CCtable[i]);
            }
            ArrayList<String> indexed = new ArrayList<>();
            String input_data = reader.read();
            System.out.println(input_data);
            String[] output = string_token.token(input_data, "\n");
            for (int i = 0; i < output.length; i++) {
                String[] temp = string_token.token(output[i], " ");
                // System.out.println(temp.length);
                if (temp[0] != "END" && temp.length == 1) {
                    // System.out.print(temp.toString());
                    temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ',' + OPTAB_data.get(temp[0]).machine_code
                            + ')';
                    output[i] = temp[0];

                } else if (temp.length == 2) {
                    temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ',' + OPTAB_data.get(temp[0]).machine_code
                            + ')';
                    try {
                        Integer.parseInt(temp[1]);
                        temp[1] = "(C," + temp[1] + ")";
                    } catch (NumberFormatException e) {
                        // Error;
                        temp[1] = "(S," + index_in_symboltable(indexed, temp[1]) + ")";
                    }
                    output[i] = temp[0] + temp[1];
                } else if (temp.length == 3 && temp[0].length() > 1) {
                    // System.out.println(temp[0] + "-" + temp[1] + "-" + temp[2]);

                    temp[0] = '(' + OPTAB_data.get(temp[0]).statement_class + ',' +
                            OPTAB_data.get(temp[0]).machine_code
                            + ')';
                    temp[1] = " " + RTtable_data.get(temp[1]).machine_code + " ";

                    try {
                        Integer.parseInt(temp[2]);
                        temp[2] = "(C," + temp[2] + ")";
                    } catch (NumberFormatException e) {
                        // Error;
                        temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                    }
                    output[i] = temp[0] + temp[1] + temp[2];
                } else if (temp.length == 3 && temp[0].length() == 1) {
                    temp[1] = '(' + OPTAB_data.get(temp[1]).statement_class + ',' +
                            OPTAB_data.get(temp[1]).machine_code
                            + ')';
                    try {
                        Integer.parseInt(temp[2]);
                        temp[2] = "(C," + temp[2] + ")";
                    } catch (NumberFormatException e) {
                        // Error;
                        temp[2] = "(S," + index_in_symboltable(indexed, temp[2]) + ")";
                    }
                    output[i] = temp[1] + temp[2];
                } else if (temp.length == 4) {
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
                    output[i] = temp[1] + temp[2] + temp[3];
                }
            }
            for (int i = 0; i < output.length; i++) {
                System.out.println(output[i]);
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static int index_in_symboltable(ArrayList<String> indexed, String S) {
        int index = 0;
        for (String str : indexed) {
            if (str.equals(S)) {
                return index+1;
                // If the string is found, return true
            }
            index++;
        }
        indexed.add(S);
        return indexed.indexOf(S)+1;
    }
}
