from ui.console import Console
from logic.controller import Controller
from repository.studentrepo import StudentRepo, FileStudentRepository

def main():
    console = Console(Controller(FileStudentRepository('students.dat')))
    console.run()

main()