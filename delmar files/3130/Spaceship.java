package proj4;

import java.util.Scanner;
public class Spaceship 
{
	
		public String shipName;
		public int engineType;
		public double maxSpeed;
		public int shipHealth;
		public int attackPower;
		public int xPosition;
		public int yPosition;
		
		public Spaceship()
		{
			shipName = "default";
			maxSpeed = (int)(Math.random() * 3 + 1);
			shipHealth = (int)(Math.random() * 50 + 50);
			attackPower = (int)(Math.random() * 15 + 5);
			xPosition = (int)(Math.random() * 10);
			yPosition = (int)(Math.random() * 10);
		}
		
		public Spaceship(String shipName)
		{
			this.shipName = shipName;
			maxSpeed = (int)(Math.random() * 3 + 1);
			shipHealth = (int)(Math.random() * 50 + 50);
			attackPower = (int)(Math.random() * 15 + 5);
			xPosition = (int)(Math.random() * 10);
			yPosition = (int)(Math.random() * 10);
		}
		
		public void moveUp()
		{
			yPosition = yPosition + (int)maxSpeed;
		}
		
		public void moveDown()
		{
			yPosition = yPosition - (int)maxSpeed;
		}
		
		public void moveLeft()
		{
			xPosition = xPosition - (int)maxSpeed;
		}
		
		public void moveRight()
		{
			xPosition = xPosition + (int)maxSpeed;
		}
		
		class Spaceship1 extends Spaceship
		{
			String name;
			
			Spaceship1()
			{
				super();
			}
			
			Spaceship1(String name)
			{
				super(name);
				this.name = name;
				
			}
			public void printShipDiagnostics()
			{
				System.out.println(this.name +":");
				System.out.println("Speed: " + super.maxSpeed);
				System.out.println("Health: " + super.shipHealth);
				System.out.println("Attack Power: " + super.attackPower);
			}
		}

		class Spaceship2 extends Spaceship
		{
			String name;
			Spaceship2()
			{
				super();
			}
			Spaceship2(String name)
			{
				super(name);
				this.name = name;
			}
			
			public void printShipDiagnostics()
			{
				System.out.println(this.name +":");
				System.out.println("Speed: " + super.maxSpeed);
				System.out.println("Health: " + super.shipHealth);
				System.out.println("Attack Power: " + super.attackPower);
			}
		}
		
		public static void printBoard(Spaceship s1, Spaceship s2)
		{
			int x1 = s1.xPosition;
			int y1 = s1.yPosition;
			int x2 = s2.xPosition;
			int y2 = s2.yPosition;
			
			String[][] array = new String[11][11];
			for(int i =0; i<11;i++)
			{
				for(int y=0;y<11;y++)
				{
					array[i][y]=" ";
				}
				
			}
			array[x1][y1]= s1.shipName;
			array[x2][y2]= s2.shipName;
			
			for(int i =0; i<11;i++)
			{
				for(int y=0;y<11;y++)
				{
					System.out.print("| " + array[i][y] + " |");
				}
				System.out.println();
				
			}
		}

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int type, choice;
		String name;
		Spaceship s = new Spaceship();
		System.out.println("Welcome Captain! What kind of starship would you like to create:");
		System.out.println("1. Federation Starship");
		System.out.println("2. Romulan Warbird");
		type = input.nextInt();
		input.nextLine();
		if(type==1)
		{
			System.out.println("You have chosen Federation Starship: What is your ship's name?");
			name = input.nextLine();
			s1 =new Spaceship1(name);
			((Spaceship1) s1).printShipDiagnostics();
		}
		else
		{
			System.out.println("You have chosen Romulan Warbird: What is your ship's name?");
			name = input.nextLine();
			s1 = new Spaceship2(name);
			((Spaceship2) s1).printShipDiagnostics();
		}
		
		System.out.println("Welcome Captain 2! What kind of starship would you like to create:");
		type = input.nextInt();
		input.nextLine();
		if(type==1)
		{
			System.out.println("You have chosen Federation Starship: What is your ship's name?");
			name = input.nextLine();
			s2 = new Spaceship1(name);
			((Spaceship1) s2).printShipDiagnostics();
		}
		else
		{
			System.out.println("You have chosen Romulan Warbird: What is your ship's name?");
			name = input.nextLine();
			s2 = new Spaceship2(name);
			((Spaceship2) s2).printShipDiagnostics();
		}
		
		System.out.println("Welcome captains. Here is your game board:");
		printBoard(s1, s2);
		
		System.out.println("Captain of the " + s1.shipName + ": How would you like to proceed?");
		System.out.println("1. Move Up");
		System.out.println("2. Move Down");
		System.out.println("3. Move Left");
		System.out.println("4. Move Right");
		
		choice = input.nextInt();
		switch(choice)
		{
		case 1:
			s1.moveUp();
			break;
		case 2:
			s1.moveDown();
			break;
		case 3:
			s1.moveLeft();
			break;
		case 4:
			s1.moveRight();
			break;
		}
		printBoard(s1, s2);
		
		System.out.println("Captain of the " + s2.shipName + ": How would you like to proceed?");
		System.out.println("1. Move Up");
		System.out.println("2. Move Down");
		System.out.println("3. Move Left");
		System.out.println("4. Move Right");
		
		choice = input.nextInt();
		switch(choice)
		{
		case 1:
			s2.moveUp();
			break;
		case 2:
			s2.moveDown();
			break;
		case 3:
			s2.moveLeft();
			break;
		case 4:
			s2.moveRight();
			break;
		}
		printBoard(s1, s2);
		//do
		//{
			
		//}while(choice != 5);
	}

}
