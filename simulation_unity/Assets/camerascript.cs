using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Text;
using System.IO;

public class camerascript : MonoBehaviour {
	public Transform cam;
	public Vector3 cameraRelative;
	public GameObject emily;
	private Vector3 emily_pos;
	private Vector3 camera;
	private float rx,ry;
	private float val;
	private float r,theta;
	private float k1 = 100.0f;
	private float k2 = 10.0f;
	public Camera cameraobj;
	public Transform world;

	//for file handling
	private List<string[]> rowData = new List<string[]>();
	/*
	void Save()
	{
		// Creating First row of titles manually..
		string[] rowDataTemp = new string[3];
		rowDataTemp [0] = "Name";
		rowDataTemp [1] = "ID";
		rowDataTemp [2] = "Income";
		rowData.Add (rowDataTemp);

		// You can add up the values in as many cells as you want.
		for (int i = 0; i < 10; i++) {
			rowDataTemp = new string[3];
			rowDataTemp [0] = "Sushanta" + i; // name
			rowDataTemp [1] = "" + i; // ID
			rowDataTemp [2] = "$" + UnityEngine.Random.Range (5000, 10000); // Income
			rowData.Add (rowDataTemp);
		}

		string[][] output = new string[rowData.Count][];

		for (int i = 0; i < output.Length; i++) {
			output [i] = rowData [i];
		}

		int length = output.GetLength (0);
		string delimiter = ",";

		StringBuilder sb = new StringBuilder ();

		for (int index = 0; index < length; index++)
			sb.AppendLine (string.Join (delimiter, output [index]));


		string filePath = getPath ();

		StreamWriter outStream = System.IO.File.CreateText (filePath);
		outStream.WriteLine (sb);
		outStream.Close ();
	}
		private string getPath(){
			#if UNITY_EDITOR
			return Application.dataPath +"/CSV/"+"Saved_data.csv";
			#elif UNITY_ANDROID
			return Application.persistentDataPath+"Saved_data.csv";
			#elif UNITY_IPHONE
			return Application.persistentDataPath+"/"+"Saved_data.csv";
			#else
			return Application.dataPath +"/"+"Saved_data.csv";
			#endif
			}
	


*/
    // Use this for initialization
    void Start () {
		camera = transform.position;
		val = 0;
		Screen.SetResolution(640, 480, true);
		//Save();
    }

    // Update is called once per frame
    void Update () {
		//Save ();
		emily_pos = emily.transform.position - transform.position;
		//print (emily_pos);
		cam = Camera.main.transform;
		Vector3 cameraRelative = cam.InverseTransformPoint (emily.transform.position);

		Vector3 cameraRelative2 = cameraobj.WorldToScreenPoint(emily.transform.position);
		//print(cameraRelative2);

		if (cameraRelative2.y!=null) {
			cameraRelative.x = cameraRelative2.x - 768.0f;
			cameraRelative.y = cameraRelative2.y - 346.5f;
		}
		//draw imaginary ellipse and check if EMILY is inside or outside the region. 
		rx = 200f;
		ry = 100f;
		val = (cameraRelative.x * cameraRelative.x) / (rx * rx) + (cameraRelative.y * cameraRelative.y) / (ry * ry);
		if (val > 1) {
			//print ("outside the ellipse ! ");
			r = Mathf.Sqrt (cameraRelative.x * cameraRelative.x + cameraRelative.y * cameraRelative.y);
			theta = Mathf.Atan (cameraRelative.x / cameraRelative.y);
			print (theta);
			if (cameraRelative.y < 0) {
				r = -1 * r;
			}
			if (theta < 0) {
				theta = -theta;
			}
			/*

			if (theta > 0 && cameraRelative.y < 0 && cameraRelative.x<0) {
				theta = -1 * theta;
			}
			if (theta < 0 && cameraRelative.y < 0 && cameraRelative.x>0) {
				theta = -1 * theta;
			}
			*/
			/*
			if (Mathf.Rad2Deg * theta > 80 || Mathf.Rad2Deg * theta < -80) {
				theta = theta*theta;
			}*/

			//print (Mathf.Rad2Deg * theta);
			//print (cameraRelative.x);
			//print (r);

			//run the control algorithm : 
			transform.Rotate (new Vector3 (0, -1, 0) * (1-k1) * theta * Time.deltaTime,Space.World);
			if (Mathf.Rad2Deg*theta<=45 && Mathf.Rad2Deg*theta>-45) {
				transform.Rotate (new Vector3 (1, 0, 0) * (1-k2) * r * Time.deltaTime,Space.Self);
			}
			//val = val - k1 * Mathf.Rad2Deg(theta) * Time.deltaTime;
		} else {
			//print ("inside the ellipse ! ");
		}
	}
    
}
